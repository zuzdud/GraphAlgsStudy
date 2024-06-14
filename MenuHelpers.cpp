//
// Created by zuzuz on 14.06.2024.
//

#include "MenuHelpers.h"

#include "utils/GraphReader.h"
#include "graph_structures/AdjacencyList.h"
#include "graph_structures/IncidenceMatrix.h"


namespace aizo {
    void readGraphFromFile(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list) {
        const GraphReader graphReader("");

        std::cout << "Enter filename: ";
        std::string fileName;
        std::getline(std::cin, fileName);

        matrix = graphReader.createIncidenceMatrixFromFile(fileName);
        list = graphReader.createAdjacencyListFromFile(fileName);
    }
}
