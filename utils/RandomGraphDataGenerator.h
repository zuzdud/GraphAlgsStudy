//
// Created by zuzuz on 14.06.2024.
//

#pragma once
#include <tuple>
#include <vector>

namespace aizo {
    class RandomGraphDataGenerator {
    public:
        static std::tuple<size_t, size_t, std::vector<size_t> > generate(
            const float density, const size_t vertexAmount, const size_t maxValue = 1000);
    };
}
