//
// Created by zuzuz on 14.06.2024.
//

#include "Edge.h"

namespace aizo {
    size_t Edge::getOrigin() const {
        return origin_;
    }

    size_t Edge::getDestination() const {
        return destination_;
    }

    size_t Edge::getWeight() const {
        return weight_;
    }

    std::shared_ptr<Edge> Edge::getPrevious() const {
        return previous_;
    }

    void Edge::setPrevious(const std::shared_ptr<Edge>& previous) {
        previous_ = previous;
    }

    std::shared_ptr<Edge> Edge::getNext() const {
        return next_;
    }

    void Edge::setNext(const std::shared_ptr<Edge>& next){
        next_ = next;
    }
}
