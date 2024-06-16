//
// Created by zuzuz on 11.06.2024.
//

#include "BellmanFord.h"

namespace aizo {
    std::vector<Edge> BellmanFord::findShortestPath(const std::unique_ptr<IncidenceMatrix> &incidenceMatrix,
                                                    const size_t from, const size_t to) {
        std::vector<Edge> resultPath;
        const size_t vertexAmount = incidenceMatrix->getVertexAmount();
        const size_t edgeAmount = incidenceMatrix->getEdgeAmount();
        const std::vector<size_t> edgeWeights = incidenceMatrix->getEdgeWeights();
        const std::vector<std::vector<MatrixCell> > matrix = incidenceMatrix->getMatrix();

        // Generate starting travel costs
        std::vector<size_t> travelCosts(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            travelCosts[i] = SIZE_MAX;
        }

        // Create array to store previous vertex
        std::vector<size_t> reachableFrom(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            reachableFrom[i] = SIZE_MAX;
        }

        // Create array to store single cost
        std::vector<size_t> reachableFor(vertexAmount);

        travelCosts[from] = 0;
        bool anyChange = true;

        // Iterate V - 1 times
        for (size_t i = 0; (i < vertexAmount - 1) && anyChange; i++) {
            anyChange = false;
            // Iterate through all vertices
            for (size_t origin = 0; origin < vertexAmount; origin++) {
                // Check if vertex was visited
                if (travelCosts[origin] == SIZE_MAX) {
                    continue;
                }
                // Iterate through all edges
                for (size_t edge = 0; edge < edgeAmount; edge++) {
                    if (matrix[origin][edge] != MatrixCell::Origin) {
                        continue;
                    }
                    // Find destination
                    for (size_t destination = 0; destination < edgeAmount; destination++) {
                        if (matrix[destination][edge] != MatrixCell::Destination) {
                            continue;
                        }
                        // Check if current travel cost is lower than old one
                        if (travelCosts[origin] + edgeWeights[edge] < travelCosts[destination]) {
                            anyChange = true;
                            travelCosts[destination] = travelCosts[origin] + edgeWeights[edge];
                            reachableFrom[destination] = origin;
                            reachableFor[destination] = edgeWeights[edge];
                        }
                        break;
                    }
                }
            }
        }
        size_t currentVertex = to;
        // Create the shortest path
        while (currentVertex != from) {
            // Check if connection exists
            if (currentVertex == SIZE_MAX) {
                return std::vector<Edge>(0);
            }

            resultPath.emplace_back(currentVertex, reachableFrom[currentVertex], reachableFor[currentVertex]);
            currentVertex = reachableFrom[currentVertex];
        }

        return resultPath;
    }

    std::vector<Edge> BellmanFord::findShortestPath(const std::unique_ptr<AdjacencyList> &adjacencyList,
                                                    const size_t from, const size_t to) {
        // Get necessary stuff from the graph
        std::vector<Edge> resultPath;
        const std::vector<std::shared_ptr<Edge> > edges = adjacencyList->getEdges();
        const size_t vertexAmount = adjacencyList->getVertexAmount();

        // Generate starting travel costs
        std::vector<size_t> travelCosts(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            travelCosts[i] = SIZE_MAX;
        }

        // Create array to store previous vertex
        std::vector<size_t> reachableFrom(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            reachableFrom[i] = SIZE_MAX;
        }

        // Create array to store single cost
        std::vector<size_t> reachableFor(vertexAmount);

        travelCosts[from] = 0;

        //Edge *edge = nullptr;
        bool anyChange = true;

        // Iterate V - 1 times
        for (size_t i = 0; i < (vertexAmount - 1) && anyChange; i++) {
            anyChange = false;

            // Iterate through all vertices
            for (size_t j = 0; j < vertexAmount; j++) {
                // Check if vertex was visited
                if (travelCosts[j] == SIZE_MAX) {
                    continue;
                }

                std::shared_ptr<Edge> edge = edges[j];
                while (edge != nullptr) {
                    // Check if current travel cost is lower than old one
                    if (travelCosts[j] + edge->getWeight() < travelCosts[edge->getDestination()]) {
                        anyChange = true;
                        travelCosts[edge->getDestination()] = travelCosts[j] + edge->getWeight();
                        reachableFrom[edge->getDestination()] = j;
                        reachableFor[edge->getDestination()] = edge->getWeight();
                    }

                    edge =  edge->getNext();
                }
            }
        }

        size_t currentVertex = to;

        // Create the shortest path
        while (currentVertex != from) {
            // Check if connection exists
            if (currentVertex == SIZE_MAX) {
                return std::vector<Edge>(0);
            }

            resultPath.emplace_back(currentVertex, reachableFrom[currentVertex], reachableFor[currentVertex]);
            currentVertex = reachableFrom[currentVertex];
        }

        return resultPath;
    }
}
