//
// Created by zuzuz on 11.06.2024.
//

#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "Edge.h"

namespace aizo {

        class AdjacencyList
        {
        public:
            AdjacencyList(const size_t edgeAmount, const size_t vertexAmount, const std::vector<size_t>& graphData);
            ~AdjacencyList() = default;
            /// <summary>
            /// Print graph to the selected ostream
            /// </summary>
            /// <param name="out"></param>
            void print(std::ostream& out) const;
            /// <summary>
            /// Get number of vertices
            /// </summary>
            /// <returns></returns>
            size_t getVertexAmount() const;
            /// <summary>
            /// Get edges handler
            /// </summary>
            /// <returns></returns>
            std::vector<std::shared_ptr<Edge>> getEdges() const;

        private:
            const size_t edgeAmount_;
            const size_t vertexAmount_;
            std::vector<std::shared_ptr<Edge>> edges_;
        };
}
