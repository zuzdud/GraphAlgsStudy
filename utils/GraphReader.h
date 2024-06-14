//
// Created by zuzuz on 14.06.2024.
//

#pragma once


#include <iostream>
#include <fstream>
#include <tuple>
#include "../graph_structures/IncidenceMatrix.h"
#include "../graph_structures/AdjacencyList.h"

namespace aizo {
    class GraphReader {
    public:
        explicit GraphReader(const std::string& basePath);

        std::unique_ptr<IncidenceMatrix> createIncidenceMatrixFromFile(const std::string &fileName) const;

        std::unique_ptr<AdjacencyList> createAdjacencyListFromFile(const std::string &fileName) const;

    private:
        const std::string basePath_;

        std::tuple<size_t, size_t, std::vector<size_t>> readData(const std::string &fileName) const;
    };
}
