//
// Created by zuzuz on 14.06.2024.
//

#pragma once

namespace aizo {
    enum class MatrixCell {
        None = 0,
        Origin = -1,
        Destination = 1
    };

    enum class TimerPrecision {
        Nanoseconds,
        Microseconds,
        Milliseconds,
        Seconds
    };

    enum class Algorithm {
        Prim,
        Kruskal,
        Dijkstra,
        BellmanFord
    };

    enum class GraphRepresentation {
        Matrix,
        List
    };
}
