//
// Created by zuzuz on 14.06.2024.
//

#include "MenuHelpers.h"

#include "../utils/GraphReader.h"
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"
#include "../utils/RandomGraphDataGenerator.h"


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

        const auto &[edgeAmount, vertexAmount, graphData] = RandomGraphDataGenerator::generate(density, vertexNumber, maxValue);

        matrix = std::make_unique<IncidenceMatrix>(edgeAmount, vertexAmount, graphData);
        list = std::make_unique<AdjacencyList>(edgeAmount, vertexAmount, graphData);

    }

    void printGraphStructures(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list) {
        if(matrix == nullptr) {
            std::cout << "No incidence matrix data" << std::endl;
        } else {
            matrix->print(std::cout);
        }

        if(list == nullptr) {
            std::cout << "No adjacency list data" << std::endl;
        } else {
            list->print(std::cout);
        }
    }

}
