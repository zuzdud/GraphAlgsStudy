cmake_minimum_required(VERSION 3.28)
project(GraphAlgsStudy)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(GraphAlgsStudy main.cpp
        menu/menu_structures/MenuItem.cpp
        menu/menu_structures/MenuItem.h
        menu/menu_structures/Menu.cpp
        menu/menu_structures/Menu.h
        menu/MenuCreator.h
        menu/MenuCreator.cpp
        graph_structures/IncidenceMatrix.cpp
        graph_structures/IncidenceMatrix.h
        graph_structures/AdjacencyList.cpp
        graph_structures/AdjacencyList.h
        Algorithms/Prim.cpp
        Algorithms/Prim.h
        Algorithms/Kruskal.cpp
        Algorithms/Kruskal.h
        Algorithms/Dijkstra.cpp
        Algorithms/Dijkstra.h
        Algorithms/BellmanFord.cpp
        Algorithms/BellmanFord.h
        utils/Enums.h
        graph_structures/Edge.h
        graph_structures/Edge.cpp
        utils/GraphReader.cpp
        utils/GraphReader.h
        menu/MstMenu.cpp
        menu/MstMenu.h
        menu/MenuHelpers.cpp
        menu/MenuHelpers.h
        utils/RandomGraphDataGenerator.cpp
        utils/RandomGraphDataGenerator.h
        menu/ShortestPathMenu.cpp
        menu/ShortestPathMenu.h
)

