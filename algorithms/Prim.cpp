//
// Created by zuzuz on 11.06.2024.
//

#include "Prim.h"
#include "../graph_structures/Edge.h"
//#include <algorithm>
#include <queue>
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"

namespace aizo {
    std::unique_ptr<IncidenceMatrix> Prim::generateMst(const std::unique_ptr<IncidenceMatrix> &incidenceMatrix) {
        // Get necessary stuff from the graph
        const size_t vertexAmount = incidenceMatrix->getVertexAmount();
        const size_t edgeNumber = incidenceMatrix->getEdgeAmount();
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

        std::vector<bool> visitedVertices(vertexAmount);

        for (size_t i = 0; i < vertexAmount; i++) {
            visitedVertices[i] = false;
        }

        size_t currentVertexIndex;
        auto pushReachableEdges = [&]() {
            for (size_t begin = 0; begin < edgeNumber; begin++) {
                if (matrix[currentVertexIndex][begin] == MatrixCell::None) {
                    continue;
                }

                for (size_t end = 0; end < vertexAmount; end++) {
                    if (matrix[end][begin] == MatrixCell::None || end == currentVertexIndex) {
                        continue;
                    }

                    if (visitedVertices[end]) {
                        continue;
                    }

                    edgesHeap.emplace(currentVertexIndex, end, edgeWeights[begin]); //śmieszny błąd tu był
                }
            }
        };
        currentVertexIndex = 0;

        visitedVertices[currentVertexIndex] = true;
        pushReachableEdges();

        for (size_t i = 0; i < vertexAmount - 1;) {
            const Edge candidate = edgesHeap.top();
            edgesHeap.pop();
            if (!visitedVertices[candidate.getDestination()]) {
                currentVertexIndex = candidate.getDestination();
                resultGraphData[3 * resultIndex] = candidate.getOrigin();
                resultGraphData[3 * resultIndex + 1] = candidate.getDestination();
                resultGraphData[3 * resultIndex + 2] = candidate.getWeight();
                visitedVertices[currentVertexIndex] = true;
                pushReachableEdges();
                resultIndex++;
                i++;
            }
        }

        return std::make_unique<IncidenceMatrix>(vertexAmount - 1, vertexAmount, resultGraphData);
    }


    std::unique_ptr<AdjacencyList> Prim::generateMst(const std::unique_ptr<AdjacencyList> &adjacencyList) {
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

        std::vector<bool> visitedVertices(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            visitedVertices[i] = false;
        }

        size_t currentVertexIndex;

        auto pushReachableEdges = [&]() {
            for (size_t begin = 0; begin < vertexAmount; begin++) {
                std::shared_ptr<Edge> edge = edges[begin];

                if (edge == nullptr) continue;

                while (edge != nullptr) {
                    if (edge->getOrigin() == currentVertexIndex && !visitedVertices[edge->getDestination()]) {
                        edgesHeap.push(*edge);
                    }
                    if (edge->getDestination() == currentVertexIndex && !visitedVertices[edge->getOrigin()]) {
                        edgesHeap.push(*edge);
                    }
                    edge = edge->getNext();
                }
            }
        };

        currentVertexIndex = 0;
        visitedVertices[currentVertexIndex] = true;
        pushReachableEdges();

        for (size_t i = 0; i < vertexAmount - 1;) {
            const Edge candidate = edgesHeap.top();
            edgesHeap.pop();

            if (!visitedVertices[candidate.getDestination()] || !visitedVertices[candidate.getOrigin()]) {
                currentVertexIndex = visitedVertices[candidate.getDestination()]
                                         ? candidate.getOrigin()
                                         : candidate.getDestination();

                resultGraphData[3 * resultIndex] = candidate.getOrigin();
                resultGraphData[3 * resultIndex + 1] = candidate.getDestination();
                resultGraphData[3 * resultIndex + 2] = candidate.getWeight();
                visitedVertices[currentVertexIndex] = true;
                pushReachableEdges();
                resultIndex++;
                i++;
            }
        }

        return std::make_unique<AdjacencyList>(vertexAmount - 1, vertexAmount, resultGraphData);
    }
}
