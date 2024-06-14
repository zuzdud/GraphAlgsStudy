//
// Created by zuzuz on 09.06.2024.
//

#include "MenuCreator.h"

#include <iostream>
#include <vector>

#include "MenuHelpers.h"
#include "MstMenu.h"
#include "../graph_structures/AdjacencyList.h"
#include "../graph_structures/IncidenceMatrix.h"
#include "menu_structures/Menu.h"
#include "menu_structures/MenuItem.h"
#include "../utils/GraphReader.h"

namespace aizo {
    void mainMenu() {
        const std::vector mainMenuItems{
            menu::MenuItem(1, "Minimum spanning tree (MST)", mstMenu),
            menu::MenuItem(2, "Shortest path", shortestPathMenu)
        };
        const menu::Menu mainMenu("Main menu", "Exit", mainMenuItems);
        mainMenu.execute();
    }
}
