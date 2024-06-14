//
// Created by zuzuz on 14.06.2024.
//

#include "GraphReader.h"

namespace aizo {
    GraphReader::GraphReader(const std::string &basePath)
        : basePath_(basePath) {
    }

    std::unique_ptr<IncidenceMatrix> GraphReader::createIncidenceMatrixFromFile(const std::string &fileName) const {
        const auto &[edgeAmount, vertexAmount, graphData] = readData(fileName);

        if (graphData.empty()) {
            return nullptr;
        }

        return std::make_unique<IncidenceMatrix>(edgeAmount, vertexAmount, graphData);
    }

    std::unique_ptr<AdjacencyList> GraphReader::createAdjacencyListFromFile(const std::string &fileName) const {
        const auto &[edgeAmount, vertexAmount, graphData] = readData(fileName);

        if (graphData.empty()) {
            return nullptr;
        }

        return std::make_unique<AdjacencyList>(edgeAmount, vertexAmount, graphData);
    }

    std::tuple<size_t, size_t, std::vector<size_t> > GraphReader::readData(const std::string &fileName) const {
        std::ifstream file(basePath_ + fileName);

        if (file.fail()) {
            return std::make_tuple(-1, -1, std::vector<size_t>{});
        }

        size_t edgeAmount, vertexAmount;
        file >> edgeAmount >> vertexAmount;

        const size_t dataAmount = edgeAmount * 3;
        std::vector<size_t> graphData(dataAmount);

        for (size_t i = 0; i < dataAmount; i++) {
            file >> graphData[i];
        }

        return std::make_tuple(edgeAmount, vertexAmount, graphData);
    }
}
