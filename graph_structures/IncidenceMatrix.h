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
        /// Get number of edges
        /// </summary>
        /// <returns></returns>
        size_t getEdgeAmount() const;
        /// <summary>
        /// Get matrix handler
        /// </summary>
        /// <returns></returns>
        std::vector<std::vector<MatrixCell>> getMatrix() const;
        /// <summary>
        /// Get array with values
        /// </summary>
        /// <returns></returns>
        std::vector<size_t> getEdgeWeights() const;

    private:
        const size_t vertexAmount_;
        const size_t edgeAmount_;
        std::vector<size_t> edgeWeights_;
        std::vector<std::vector<MatrixCell>> matrixData_;
    };
}
