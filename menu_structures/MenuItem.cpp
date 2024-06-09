//
// Created by zuzuz on 09.06.2024.
//

#include "MenuItem.h"

namespace menu {
    int MenuItem::getId() const{
        return id_;
    }

    std::string MenuItem::getName() const {
        return name_;
    }

    void MenuItem::execute() const {
        func_();
    }

} // menu_structures