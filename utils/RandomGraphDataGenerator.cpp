//
// Created by zuzuz on 14.06.2024.
//

#include "RandomGraphDataGenerator.h"

#include <random>

namespace aizo {
    std::tuple<size_t, size_t, std::vector<size_t> > RandomGraphDataGenerator::generate(
        const float density, const size_t vertexAmount, const size_t maxValue) {
        const size_t minimumEdgeNumber = vertexAmount;
        size_t edgeAmount = (density * vertexAmount * (vertexAmount - 1)) / 2;
        edgeAmount = edgeAmount > minimumEdgeNumber ? edgeAmount : minimumEdgeNumber;
        const size_t dataSize = 3 * edgeAmount;
        std::vector<size_t> data(dataSize);

        // Create random device
        std::random_device seed;
        std::mt19937 gen(seed());
        std::uniform_int_distribution<size_t> values(1, maxValue);
        std::uniform_int_distribution<size_t> vertices(0, vertexAmount - 1);

        // Create array to store information about connections
        std::vector<std::vector<bool> > connections(edgeAmount);
        for (size_t i = 0; i < edgeAmount; i++) {
            connections[i].resize(edgeAmount);
        }

        // Create ring to connect all vertices
        for (size_t i = 0; i < minimumEdgeNumber - 1; i++) {
            data[3 * i] = i;
            data[3 * i + 1] = i + 1;
            data[3 * i + 2] = values(gen);
            connections[i][i + 1] = true;
            connections[i + 1][i] = true;
        }

        data[3 * (minimumEdgeNumber - 1)] = minimumEdgeNumber - 1;
        data[3 * (minimumEdgeNumber - 1) + 1] = 0;
        data[3 * (minimumEdgeNumber - 1) + 2] = values(gen);
        connections[minimumEdgeNumber - 1][0] = true;
        connections[0][minimumEdgeNumber - 1] = true;

        // Generete rest of edges
        for (size_t i = minimumEdgeNumber; i < edgeAmount; i++) {
            size_t origin = vertices(gen);
            size_t destination = vertices(gen);

            while (origin == destination || connections[origin][destination]) {
                origin = vertices(gen);
                destination = vertices(gen);
            }

            data[3 * i] = origin;
            data[3 * i + 1] = destination;
            data[3 * i + 2] = values(gen);

            connections[origin][destination] = true;
            connections[destination][origin] = true;
        }

        return std::make_tuple(edgeAmount, vertexAmount, data);
    }
}
