//
// Created by zuzuz on 11.06.2024.
//

#pragma once

#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"

namespace aizo {
    class Kruskal {
    public:
        static std::unique_ptr<IncidenceMatrix> generateMst(const std::unique_ptr<IncidenceMatrix> &incidenceMatrix);

        static std::unique_ptr<AdjacencyList> generateMst(const std::unique_ptr<AdjacencyList> &adjacencyList);
    };
}
