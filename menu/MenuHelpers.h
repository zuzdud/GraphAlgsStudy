//
// Created by zuzuz on 14.06.2024.
//

#pragma once
#include <memory>

namespace aizo {
    class AdjacencyList;
    class IncidenceMatrix;

    void readGraphFromFile(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list);
    void generateRandomGraphData(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list);
    void printGraphStructures(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list);
    void runPrimAlgorithm(const std::unique_ptr<IncidenceMatrix> &matrix, const std::unique_ptr<AdjacencyList> &list);
}
