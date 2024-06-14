//
// Created by zuzuz on 11.06.2024.
//

#include "AdjacencyList.h"

#include <iomanip>

namespace aizo {
    AdjacencyList::AdjacencyList(const size_t edgeAmount, const size_t vertexAmount,
                                 const std::vector<size_t> &graphData): edgeAmount_(edgeAmount), vertexAmount_(vertexAmount), edges_(vertexAmount_) {
        const size_t dataAmount = 3 * edgeAmount_;
        size_t currentIndex = 0;

        while (currentIndex < dataAmount) {
            // Get edge from array
            std::shared_ptr<Edge> edge = edges_[graphData[currentIndex]];

            // Check if edge exists
            if (edge == nullptr) {
                // Create new edge
                edges_[graphData[currentIndex]] = std::make_shared<Edge>(graphData[currentIndex], graphData[currentIndex + 1],
                                                           graphData[currentIndex + 2]);
                currentIndex += 3;
                continue;
            }

            // Find the last next edge
            while (edge->getNext() != nullptr) {
                edge = edge->getNext();
            }

            // Create new edge
            edge->setNext(std::make_shared<Edge>(graphData[currentIndex], graphData[currentIndex + 1], graphData[currentIndex + 2]));
            edge->getNext()->setPrevious(edge);
            currentIndex += 3;
        }
    }

    void AdjacencyList::print(std::ostream &out) const {

        // Iterate through all vertices
        for (size_t i = 0; i < vertexAmount_; i++) {
            out << std::setw(2) << i << " --> ";

            // Get edge from index
            std::shared_ptr<Edge> edge = edges_[i];

            // Check if edge exists
            if (edge == nullptr) {
                out << std::endl;
                continue;
            }

            while (edge != nullptr) {
                // Display edge
                out << std::setw(2) << edge->getDestination() << '[' << std::setw(2) << edge->getWeight() << "] | ";
                edge = edge->getNext();
            }

            out << std::endl;
        }
    }

    size_t AdjacencyList::getVertexAmount() const {
        return vertexAmount_;
    }

    std::vector<std::shared_ptr<Edge>> AdjacencyList::getEdges() const {
        return edges_;
    }
}
