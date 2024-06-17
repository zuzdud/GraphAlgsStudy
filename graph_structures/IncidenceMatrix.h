//
// Created by zuzuz on 11.06.2024.
//

#pragma once

#include "../utils/Enums.h"
#include <ostream>
#include <vector>

namespace aizo
{
    class IncidenceMatrix
    {
    public:
        IncidenceMatrix(const size_t edgeAmount, const size_t vertexAmount, const std::vector<size_t>& graphData);
        ~IncidenceMatrix() = default;

        void print(std::ostream& out) const;

        size_t getVertexAmount() const;

        size_t getEdgeAmount() const;

        std::vector<std::vector<MatrixCell>> getMatrix() const;

        std::vector<size_t> getEdgeWeights() const;

    private:
        const size_t vertexAmount_;
        const size_t edgeAmount_;
        std::vector<size_t> edgeWeights_;
        std::vector<std::vector<MatrixCell>> matrixData_;
    };
}
