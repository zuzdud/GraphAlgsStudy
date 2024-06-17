//
// Created by zuzuz on 11.06.2024.
//

#include "IncidenceMatrix.h"

#include <iomanip>

namespace aizo {
    IncidenceMatrix::IncidenceMatrix(
        const size_t edgeAmount, const size_t vertexAmount, const std::vector<size_t> &graphData)
        : vertexAmount_(vertexAmount), edgeAmount_(edgeAmount), edgeWeights_(edgeAmount_), matrixData_(vertexAmount_) {

        // Iterate through all vertices
        for (size_t i = 0; i < vertexAmount; i++) {
            // Create new 1D array
            matrixData_[i].resize(edgeAmount_);
        }

        int dataIndex = 0;
        int weightIndex = 0;
        for (size_t i = 0; i < edgeAmount_; i++) {
            // Read data from zuzut
            matrixData_[graphData[dataIndex]][i] = MatrixCell::Origin;
            dataIndex++;
            matrixData_[graphData[dataIndex]][i] = MatrixCell::Destination;
            dataIndex++;
            edgeWeights_[weightIndex] = graphData[dataIndex];
            dataIndex++;
            weightIndex++;
        }
    }

    void IncidenceMatrix::print(std::ostream &out) const {
        out << "       ";

        // Iterate through all edges
        for (size_t i = 0; i < edgeAmount_; i++) {
            out << std::setw(2) << i << "   ";
        }

        out << std::endl;

        // Iterate through all vertices
        for (size_t i = 0; i < vertexAmount_; i++) {
            // Display row
            out << std::setw(5) << i << "  ";
            for (size_t j = 0; j < edgeAmount_; j++) {
                out << std::setw(2) << static_cast<int>(matrixData_[i][j]) << " | ";
            }
            out << std::endl;
        }

        out << "weights";

        // Iterate through all edges
        for (size_t i = 0; i < edgeAmount_; i++) {
            // Display values
            out << std::setw(2) << edgeWeights_[i] << " | ";
        }

        out << std::endl;
    }

    size_t IncidenceMatrix::getVertexAmount() const {
        return vertexAmount_;
    }

    size_t IncidenceMatrix::getEdgeAmount() const {
        return edgeAmount_;
    }

    std::vector<std::vector<MatrixCell>> IncidenceMatrix::getMatrix() const {
        return matrixData_;
    }

    std::vector<size_t> IncidenceMatrix::getEdgeWeights() const {
        return edgeWeights_;
    }
}
