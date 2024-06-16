//
// Created by zuzuz on 14.06.2024.
//

#include "MenuHelpers.h"

#include "../utils/GraphReader.h"
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"
#include "../utils/RandomGraphDataGenerator.h"
#include "../algorithms/Prim.h"
#include "../algorithms/Kruskal.h"
#include "../algorithms/Dijkstra.h"

namespace aizo {
    void readGraphFromFile(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list) {
        const GraphReader graphReader("");

        std::cout << "Enter filename: ";
        std::string fileName;
        std::getline(std::cin, fileName);

        matrix = graphReader.createIncidenceMatrixFromFile(fileName);
        list = graphReader.createAdjacencyListFromFile(fileName);
    }

    void generateRandomGraphData(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list) {
        std::cout << "Enter number of vertices: ";
        size_t vertexNumber;
        std::cin >> vertexNumber;
        std::cin.clear();
        std::cin.sync();

        std::cout << "Enter density: ";
        float density;
        std::cin >> density;
        std::cin.clear();
        std::cin.sync();

        if (density > 1) {
            density = 1;
        }

        std::cout << "Enter max value: ";
        size_t maxValue;
        std::cin >> maxValue;
        std::cin.clear();
        std::cin.sync();

        const auto &[edgeAmount, vertexAmount, graphData] = RandomGraphDataGenerator::generate(
            density, vertexNumber, maxValue);

        matrix = std::make_unique<IncidenceMatrix>(edgeAmount, vertexAmount, graphData);
        list = std::make_unique<AdjacencyList>(edgeAmount, vertexAmount, graphData);
    }

    void printGraphStructures(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list) {
        if (matrix == nullptr) {
            std::cout << "No incidence matrix data" << std::endl;
        } else {
            matrix->print(std::cout);
        }

        if (list == nullptr) {
            std::cout << "No adjacency list data" << std::endl;
        } else {
            list->print(std::cout);
        }
    }

    void runPrimAlgorithm(const std::unique_ptr<IncidenceMatrix> &matrix, const std::unique_ptr<AdjacencyList> &list) {
        std::cout << "Matrix:" << std::endl;
        const auto matrixMst = Prim::generateMst(matrix);
        matrixMst->print(std::cout);

        std::cout << "List:" << std::endl;
        const auto listMst = Prim::generateMst(list);
        listMst->print(std::cout);
    }

    void runKruskalAlgorithm(const std::unique_ptr<IncidenceMatrix> &matrix,
                             const std::unique_ptr<AdjacencyList> &list) {
        std::cout << "Matrix:" << std::endl;
        const auto matrixMst = Kruskal::generateMst(matrix);
        matrixMst->print(std::cout);

        std::cout << "List:" << std::endl;
        const auto listMst = Kruskal::generateMst(list);
        listMst->print(std::cout);
    }

    void runDijkstraAlgorithm(const std::unique_ptr<IncidenceMatrix> &matrix,
                              const std::unique_ptr<AdjacencyList> &list) {
        std::cout << "Enter start vertex: ";
        size_t startVertex;
        std::cin >> startVertex;
        std::cin.clear();
        std::cin.sync();

        std::cout << "Enter end vertex: ";
        size_t endVertex;
        std::cin >> endVertex;
        std::cin.clear();
        std::cin.sync();

        size_t totalWeight = 0;
        std::cout << "Structure: matrix" << std::endl;
        const auto matrixPath = Dijkstra::findShortestPath(matrix, startVertex, endVertex);
        for (const auto &edge: matrixPath) {
            std::cout << edge.getOrigin() << "<--" << edge.getDestination() << " [" << edge.getWeight() << "] | ";
            totalWeight += edge.getWeight();
        }
        std::cout << std::endl << "Total weight: " << totalWeight << std::endl;

        totalWeight = 0;
        std::cout << std::endl << "List:" << std::endl;
        const auto listPath = Dijkstra::findShortestPath(list, startVertex, endVertex);
        for (const auto &edge: listPath) {
            std::cout << edge.getOrigin() << "<--" << edge.getDestination() << " [" << edge.getWeight() << "] | ";
            totalWeight += edge.getWeight();
        }
        std::cout << std::endl << "Total weight: " << totalWeight << std::endl;
    }
}
