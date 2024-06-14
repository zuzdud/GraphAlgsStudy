//
// Created by zuzuz on 14.06.2024.
//

#pragma once

#include <ostream>
#include <memory>

namespace aizo {
    class Edge {
    public:
        Edge(const size_t origin, const size_t destination, const size_t weight)
            : previous_(nullptr), next_(nullptr), origin_(origin), destination_(destination), weight_(weight) {
        }

        Edge() : previous_(nullptr), next_(nullptr), origin_(0), destination_(0), weight_(0) {
        }

        friend std::ostream &operator<<(std::ostream &stream, const Edge &edge) {
            stream << edge.origin_ << " --> " << edge.destination_ << " [" << edge.weight_ << ']';

            return stream;
        }

        friend bool operator==(Edge const &first, Edge const &second) {
            return first.weight_ == second.weight_;
        }

        size_t getOrigin() const;

        size_t getDestination() const;

        size_t getWeight() const;

        std::shared_ptr<Edge> getPrevious() const;

        void setPrevious(const std::shared_ptr<Edge> &previous);

        std::shared_ptr<Edge> getNext() const;

        void setNext(const std::shared_ptr<Edge> &next);

    private:
        std::shared_ptr<Edge> previous_;
        std::shared_ptr<Edge> next_;
        const size_t origin_;
        const size_t destination_;
        const size_t weight_;
    };
} // aizo
