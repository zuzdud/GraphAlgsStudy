//
// Created by zuzuz on 11.06.2024.
//

#pragma once

#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"

namespace aizo {
    class Kruskal {
    public:

        void findMinimumSpanningTree(IncidenceMatrix incidenceMatrix);

        void findMinimumSpanningTree(AdjacencyList adjacencyList);
    };
}
