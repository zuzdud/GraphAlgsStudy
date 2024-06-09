//
// Created by zuzuz on 09.06.2024.
//

#include "menu_creator.h"

#include <iostream>
#include <vector>

#include "menu_structures/Menu.h"
#include "menu_structures/MenuItem.h"

void mainMenu() {
    const std::vector mainMenuItems{
        menu::MenuItem(1, "Minimum spanning tree (MST)", mstMenu),
        menu::MenuItem(2, "Shortest path", shortestPathMenu)
    };
    const menu::Menu mainMenu("Main menu", "Exit", mainMenuItems);
    mainMenu.execute();
}

void mstMenu() {
    const std::vector mstMenuItems{
        menu::MenuItem(1, "Get data from file", []() { std::cout << "from file" << std::endl; }),
        menu::MenuItem(2, "Generate random graph", []() { std::cout << "random" << std::endl; }),
        menu::MenuItem(3, "Display graph", []() { std::cout << "display" << std::endl; }),
        menu::MenuItem(4, "Solve using Prim algorithm", []() { std::cout << "prim" << std::endl; }),
        menu::MenuItem(5, "Solve using Kruskal algorithm", []() { std::cout << "kruskla" << std::endl; })
    };
    const menu::Menu mstMenu("Minumum spanning tree menu", "Back", mstMenuItems);
    mstMenu.execute();
}

void shortestPathMenu() {
    const std::vector mstMenuItems{
        menu::MenuItem(1, "Get data from file", []() { std::cout << "from file" << std::endl; }),
        menu::MenuItem(2, "Generate random graph", []() { std::cout << "random" << std::endl; }),
        menu::MenuItem(3, "Display graph", []() { std::cout << "display" << std::endl; }),
        menu::MenuItem(4, "Solve using Dijkstra algorithm", []() { std::cout << "Dijkstra" << std::endl; }),
        menu::MenuItem(5, "Solve using Bellman - Ford algorithm", []() { std::cout << "Bellman" << std::endl; })
    };
    const menu::Menu mstMenu("Shortest path menu", "Back", mstMenuItems);
    mstMenu.execute();
}
