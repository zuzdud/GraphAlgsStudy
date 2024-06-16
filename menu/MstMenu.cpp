//
// Created by zuzuz on 14.06.2024.
//

#include "MstMenu.h"

#include "MenuHelpers.h"
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"
#include "menu_structures/Menu.h"
#include "menu_structures/MenuItem.h"
#include "../utils/GraphReader.h"

namespace aizo {
    void mstMenu() {
        std::unique_ptr<IncidenceMatrix> matrix;
        std::unique_ptr<AdjacencyList> list;
        const std::vector mstMenuItems{
            menu::MenuItem(1, "Get data from file", [&matrix, &list]() { readGraphFromFile(matrix, list); }),
            menu::MenuItem(2, "Generate random graph", [&matrix, &list]() { generateRandomGraphData(matrix, list); }),
            menu::MenuItem(3, "Display graph", [&matrix, &list]() { printGraphStructures(matrix, list); }),
            menu::MenuItem(4, "Solve using Prim algorithm", [&matrix, &list]() { runPrimAlgorithm(matrix, list); }),
            menu::MenuItem(5, "Solve using Kruskal algorithm", []() { std::cout << "kruskla" << std::endl; })
        };
        const menu::Menu mstMenu("Minimum spanning tree menu", "Back", mstMenuItems);
        mstMenu.execute();
    }
}
