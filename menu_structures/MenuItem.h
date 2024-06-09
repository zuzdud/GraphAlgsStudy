//
// Created by zuzuz on 09.06.2024.
//

#pragma once

#include <string>
#include <functional>
#include <iostream>

namespace menu {
    class MenuItem {
        const int id_ = -1;
        const std::string name_;
        const std::function<void()> &func_;

    public:
        MenuItem(const int id, const std::string &name, const std::function<void()> &func)
            : id_(id), name_(name), func_(func) {
        }

        int getId() const;
        std::string getName() const;
        void execute() const;
    };
} // menu_structures
