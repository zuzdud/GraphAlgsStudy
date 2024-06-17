//
// Created by zuzuz on 11.06.2024.
//

#pragma once
#include <vector>

#include "../graph_structures/Edge.h"
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"

namespace aizo {
    class IncidenceMatrix;

    class Dijkstra {
    public:
        static std::vector<Edge> findShortestPath(const std::unique_ptr<IncidenceMatrix> &incidenceMatrix, size_t from,
                                                  size_t to);

        static std::vector<Edge> findShortestPath(const std::unique_ptr<AdjacencyList> &adjacencyList, size_t from,
                                                  size_t to);
    };
}
