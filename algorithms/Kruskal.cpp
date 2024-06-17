//
// Created by zuzuz on 11.06.2024.
//

#include "Kruskal.h"

#include <queue>

namespace aizo {
    std::unique_ptr<IncidenceMatrix> Kruskal::generateMst(const std::unique_ptr<IncidenceMatrix> &incidenceMatrix) {
        const size_t vertexAmount = incidenceMatrix->getVertexAmount();
        const size_t edgeAmount = incidenceMatrix->getEdgeAmount();
        const std::vector<size_t> edgeWeights = incidenceMatrix->getEdgeWeights();
        const std::vector<std::vector<MatrixCell> > matrix = incidenceMatrix->getMatrix();

        const size_t resultSize = (vertexAmount - 1) * 3;
        std::vector<size_t> resultGraphData(resultSize);
        size_t resultIndex = 0;

        class myComparator {
        public:
            bool operator()(const Edge &e1, const Edge &e2) const {
                return e1.getWeight() > e2.getWeight();
            }
        };

        std::priority_queue<Edge, std::vector<Edge>, myComparator> edgesHeap;

        std::vector<size_t> treesIds(vertexAmount);

        for (size_t i = 0; i < vertexAmount; i++) {
            treesIds[i] = i;
        }

        for (size_t edge = 0; edge < edgeAmount; edge++) {
            //auto edgeBuff = Edge(-1, -1, edgeWeights[edge]);
            size_t newEdgeOrigin = -1;
            size_t newEdgeDestination = -1;
            size_t newEdgeWeight = edgeWeights[edge];

            // Iterate through all vertices and add them to the heap
            for (size_t vertex = 0; vertex < vertexAmount; vertex++) {
                if (matrix[vertex][edge] == MatrixCell::Origin) {
                    newEdgeOrigin = vertex;
                }

                if (matrix[vertex][edge] == MatrixCell::Destination) {
                    newEdgeDestination = vertex;
                }
            }
            edgesHeap.emplace(newEdgeOrigin, newEdgeDestination, newEdgeWeight);
        }

        while (!edgesHeap.empty()) {
            const Edge nowCheckedEdge = edgesHeap.top();
            edgesHeap.pop();
            // Check if tree ids are different
            if (treesIds[nowCheckedEdge.getOrigin()] != treesIds[nowCheckedEdge.getDestination()]) {
                // Add edge to the result
                resultGraphData[3 * resultIndex] = nowCheckedEdge.getOrigin();
                resultGraphData[3 * resultIndex + 1] = nowCheckedEdge.getDestination();
                resultGraphData[3 * resultIndex + 2] = nowCheckedEdge.getWeight();

                // Correct tree ids
                int oldTreeId = treesIds[nowCheckedEdge.getOrigin()];
                int newTreeId = treesIds[nowCheckedEdge.getDestination()];
                for (size_t id = 0; id < vertexAmount; id++) {
                    if (treesIds[id] == oldTreeId) {
                        treesIds[id] = newTreeId;
                    }
                }
                resultIndex++;
            }
        }
        // Create result tree
        return std::make_unique<IncidenceMatrix>(vertexAmount - 1, vertexAmount, resultGraphData);
    }

    std::unique_ptr<AdjacencyList> Kruskal::generateMst(const std::unique_ptr<AdjacencyList> &adjacencyList) {
        const size_t vertexAmount = adjacencyList->getVertexAmount();

        const size_t resultSize = (vertexAmount - 1) * 3;
        std::vector<size_t> resultGraphData(resultSize);
        size_t resultIndex = 0;

        std::vector<std::shared_ptr<Edge> > edges = adjacencyList->getEdges();

        class myComparator {
        public:
            int operator()(const Edge &e1, const Edge &e2) const {
                return e1.getWeight() > e2.getWeight();
            }
        };

        std::priority_queue<Edge, std::vector<Edge>, myComparator> edgesHeap;

        std::vector<size_t> treesIds(vertexAmount);

        for (size_t i = 0; i < vertexAmount; i++) {
            treesIds[i] = i;
        }

        // Iterate through all vertices and add them to the heap
        for (size_t vertex = 0; vertex < vertexAmount; vertex++) {
            std::shared_ptr<Edge> nowCheckedEdge = edges[vertex];

            while (nowCheckedEdge != nullptr) {
                edgesHeap.emplace(*nowCheckedEdge);
                nowCheckedEdge = nowCheckedEdge->getNext();
            }
        }

        while (!edgesHeap.empty()) {
            const Edge nowCheckedEdge = edgesHeap.top();
            edgesHeap.pop();

            // Check if tree ids are different
            if (treesIds[nowCheckedEdge.getOrigin()] != treesIds[nowCheckedEdge.getDestination()]) {
                // Add edge to the result
                resultGraphData[3 * resultIndex] = nowCheckedEdge.getOrigin();
                resultGraphData[3 * resultIndex + 1] = nowCheckedEdge.getDestination();
                resultGraphData[3 * resultIndex + 2] = nowCheckedEdge.getWeight();

                // Correct tree ids
                int oldTreeId = treesIds[nowCheckedEdge.getOrigin()];
                int newTreeId = treesIds[nowCheckedEdge.getDestination()];
                for (size_t id = 0; id < vertexAmount; id++) {
                    if (treesIds[id] == oldTreeId)
                        treesIds[id] = newTreeId;
                }

                resultIndex++;
            }
        }

        return std::make_unique<AdjacencyList>(vertexAmount - 1, vertexAmount, resultGraphData);
    }
}
