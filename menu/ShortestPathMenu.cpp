//
// Created by zuzuz on 14.06.2024.
//

#include "ShortestPathMenu.h"

#include "MenuHelpers.h"
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"
#include "menu_structures/Menu.h"
#include "menu_structures/MenuItem.h"
#include "../utils/GraphReader.h"

namespace aizo {
    class AdjacencyList;
    class IncidenceMatrix;

    void shortestPathMenu() {
        std::unique_ptr<IncidenceMatrix> matrix;
        std::unique_ptr<AdjacencyList> list;
        const std::vector shortestPathMenuItems{
            menu::MenuItem(1, "Get data from file", [&matrix, &list]() { readGraphFromFile(matrix, list); }),
            menu::MenuItem(2, "Generate random graph", [&matrix, &list]() { generateRandomGraphData(matrix, list); }),
            menu::MenuItem(3, "Display graph", [&matrix, &list]() { printGraphStructures(matrix, list); }),
            menu::MenuItem(4, "Solve using Dijkstra algorithm",
                           [&matrix, &list]() { runDijkstraAlgorithm(matrix, list); }),
            menu::MenuItem(5, "Solve using Bellman - Ford algorithm", []() { std::cout << "Bellman" << std::endl; })
        };
        const menu::Menu spMenu("Shortest path menu", "Back", shortestPathMenuItems);
        spMenu.execute();
    }
}
