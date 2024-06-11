//
// Created by zuzuz on 11.06.2024.
//

#pragma once

#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"

class Dijkstra {
public:

    void findShortestPath(IncidenceMatrix incidenceMatrix, int startVertex, int endVertex);

    void findShortestPath(AdjacencyList adjacencyList, int startVertex, int endVertex);
};
