//
// Created by zuzuz on 09.06.2024.
//

#pragma once

#include <istream>
#include <string>
#include <vector>

#include "MenuItem.h"

namespace menu {
    class Menu {
        const std::string header_;
        const std::string exitOption_;
        const std::vector<MenuItem> items_;

        std::string toString() const;

    public:
        Menu(const std::string header, const std::string exitOpt,
             const std::vector<MenuItem> &items) : header_(header), exitOption_(exitOpt), items_(items) {
        }

        void executeItem(const int itemId) const;

        void execute() const;
    };

    std::iostream operator<<(const std::iostream &stream, const Menu &menu);
} // menu
