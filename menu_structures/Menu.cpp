//
// Created by zuzuz on 09.06.2024.
//

#include "Menu.h"

#include <algorithm>
#include <iostream>
#include <sstream>

namespace menu {
    namespace {
        bool isNumber(const std::string &s) {
            return !s.empty() && std::find_if(s.begin(),
                                              s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
        }
    }

    std::string Menu::toString() const {
        std::stringstream ss;
        ss << header_ << std::endl;
        for (const auto &item: items_) {
            ss << item.getId() << ". " << item.getName() << std::endl;
        }
        return ss.str();
    }

    void Menu::executeItem(const int itemId) const {
        const auto &foundItem = std::find_if(items_.begin(), items_.end(), [&itemId](const auto &item) {
            return itemId == item.getId();
        });

        if (foundItem == items_.end()) {
            std::cout << "ERROR: u fkd up" << std::endl;
            return;
        }

        foundItem->execute();
    }

    void Menu::execute() const {
        bool loopShouldRun = true;
        while (loopShouldRun) {
            std::cout << toString() << std::endl;
            std::cout << exitOption_ << ": type x" << std::endl;
            std::string line;
            std::getline(std::cin, line);

            if (isNumber(line)) {
                executeItem(std::stoi(line));
            }
            else if (line == "x") {
                loopShouldRun = false;
            }
            else {
                std::cout << "ERROR: u fkd up" << std::endl;
            }
        }
    }
} // menu
