//
// Created by zuzuz on 09.06.2024.
//

#include "menu_creator.h"

#include <iostream>
#include <vector>

#include "MenuHelpers.h"
#include "MstMenu.h"
#include "graph_structures/AdjacencyList.h"
#include "graph_structures/IncidenceMatrix.h"
#include "menu_structures/Menu.h"
#include "menu_structures/MenuItem.h"
#include "utils/GraphReader.h"

namespace aizo {
    void mainMenu() {
        const std::vector mainMenuItems{
            menu::MenuItem(1, "Minimum spanning tree (MST)", mstMenu),
            menu::MenuItem(2, "Shortest path", shortestPathMenu)
        };
        const menu::Menu mainMenu("Main menu", "Exit", mainMenuItems);
        mainMenu.execute();
    }

    void shortestPathMenu() {
        std::unique_ptr<IncidenceMatrix> matrix;
        std::unique_ptr<AdjacencyList> list;
        const std::vector shortestPathMenuItems{
            menu::MenuItem(1, "Get data from file", [&matrix, &list]() { readGraphFromFile(matrix, list); }),
            menu::MenuItem(2, "Generate random graph", []() { std::cout << "random" << std::endl; }),
            menu::MenuItem(3, "Display graph", [&matrix, &list]() {
                matrix->print(std::cout);
                list->print(std::cout);
            }),
            menu::MenuItem(4, "Solve using Dijkstra algorithm", []() { std::cout << "Dijkstra" << std::endl; }),
            menu::MenuItem(5, "Solve using Bellman - Ford algorithm", []() { std::cout << "Bellman" << std::endl; })
        };
        const menu::Menu spMenu("Shortest path menu", "Back", shortestPathMenuItems);
        spMenu.execute();
    }
}
