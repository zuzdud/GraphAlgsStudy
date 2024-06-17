//
// Created by zuzuz on 11.06.2024.
//

#include "Dijkstra.h"
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"

namespace aizo {
    std::vector<Edge> Dijkstra::findShortestPath(const std::unique_ptr<IncidenceMatrix> &incidenceMatrix, const size_t from,
                                                 const size_t to) {
        std::vector<Edge> resultPath;
        const size_t vertexAmount = incidenceMatrix->getVertexAmount();
        const size_t edgeAmount = incidenceMatrix->getEdgeAmount();
        const std::vector<size_t> edgeWeights = incidenceMatrix->getEdgeWeights();
        const std::vector<std::vector<MatrixCell> > matrix = incidenceMatrix->getMatrix();

        // vector for visited bool
        std::vector<bool> visitedVertices(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            visitedVertices[i] = false;
        }

        // generate starting travel costs
        std::vector<size_t> travelCosts(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            travelCosts[i] = SIZE_MAX;
        }

        // create array to store previous vertex
        std::vector<size_t> reachableFrom(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            reachableFrom[i] = SIZE_MAX;
        }

        // create array to store single cost
        std::vector<size_t> reachableFor(vertexAmount);

        travelCosts[from] = 0;
        size_t currentVertex = from;
        size_t unvisitedVerticesNumber = vertexAmount;

        // find new current vertex
        auto assignNewCurrentVertex = [&]() {
            visitedVertices[currentVertex] = true;
            unvisitedVerticesNumber--;
            size_t shortestPath = SIZE_MAX;
            for (size_t vertex = 0; vertex < vertexAmount; vertex++) {
                if (visitedVertices[vertex] == false && travelCosts[vertex] < shortestPath) {
                    shortestPath = travelCosts[vertex];
                    currentVertex = vertex;
                }
            }
        };

        // while unvisited vertices exist
        while (unvisitedVerticesNumber > 0) {
            // Iterate through all edges
            for (size_t edge = 0; edge < edgeAmount; edge++) {
                if (matrix[currentVertex][edge] != MatrixCell::Origin) {
                    continue;
                }

                // Iterate through all vertices
                for (size_t vertex = 0; vertex < vertexAmount; vertex++) {
                    if (matrix[vertex][edge] != MatrixCell::Destination) {
                        continue;
                    }

                    // Check if current travel cost is lower than old one
                    if (travelCosts[currentVertex] + edgeWeights[edge] < travelCosts[vertex]) {
                        travelCosts[vertex] = travelCosts[currentVertex] + edgeWeights[edge];
                        reachableFrom[vertex] = currentVertex;
                        reachableFor[vertex] = edgeWeights[edge];
                    }
                    break;
                }
            }

            // assign new current vetrex
            assignNewCurrentVertex();
        }

        currentVertex = to;

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


    std::vector<Edge> Dijkstra::findShortestPath(const std::unique_ptr<AdjacencyList> &adjacencyList, const size_t from,
                                                 const size_t to) {
        std::vector<Edge> resultPath;
        const std::vector<std::shared_ptr<Edge> > edges = adjacencyList->getEdges();
        const size_t vertexAmount = adjacencyList->getVertexAmount();

        std::vector<bool> visitedVertices(vertexAmount);
        for (size_t i = 0; i < vertexAmount; i++) {
            visitedVertices[i] = false;
        }

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
        size_t currentVertex = from;
        size_t unvisitedVerticesNumber = vertexAmount;

        // Find new current vertex
        auto assignNewCurrentVertex = [&]() {
            visitedVertices[currentVertex] = true;
            unvisitedVerticesNumber--;
            size_t shortestPath = SIZE_MAX;
            for (size_t vertex = 0; vertex < vertexAmount; vertex++) {
                if (visitedVertices[vertex] == false && travelCosts[vertex] < shortestPath) {
                    shortestPath = travelCosts[vertex];
                    currentVertex = vertex;
                }
            }
        };

        // While exists unvisited vertices
        while (unvisitedVerticesNumber > 0) {
            std::shared_ptr<Edge> edge = edges[currentVertex];
            while (edge != nullptr) {
                // Check if current travel cost is lower than old one
                if (travelCosts[currentVertex] + edge->getWeight() < travelCosts[edge->getDestination()]) {
                    travelCosts[edge->getDestination()] = travelCosts[currentVertex] + edge->getWeight();
                    reachableFrom[edge->getDestination()] = currentVertex;
                    reachableFor[edge->getDestination()] = edge->getWeight();
                }
                edge = edge->getNext();
            }
            // Assing new current vetrex
            assignNewCurrentVertex();
        }
        currentVertex = to;

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
