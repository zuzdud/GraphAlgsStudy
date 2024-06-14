//
// Created by zuzuz on 14.06.2024.
//

#pragma once
#include <memory>

namespace aizo {
    class AdjacencyList;
    class IncidenceMatrix;

    void readGraphFromFile(std::unique_ptr<IncidenceMatrix> &matrix, std::unique_ptr<AdjacencyList> &list);
}
