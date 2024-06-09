#include <fstream>
#include <iostream>
#include <set>

#include "menu_creator.h"

//TODO get nodes count and density from user
//TODO generate random graph
//TODO open file
//TODO alocate data structure
//TODO get data from file and get it to the structure
//TODO display data on the screen list and matrix
//TODO implement MST prims algorithm
//TODO implement MST Kruskals algorithm
//TODO implement SP Dijkstras algorithm
//TODO implement SP Ford-Bellmans algorithm
//TODO measure time

// void getGraphInfo(const std::string &fileName, int nodesNumber, int edgesNumber) {
//     std::fstream file(fileName, std::ios_base::in);
//     if (file.is_open()) {
//         file >> edgesNumber >> nodesNumber;
//     } else {
//         std::cout << "Unable to open the file" << std::endl;
//     }
// }
//
// void displayMatrix(const int v, const int e, int* matrix[]) {
//     for(int i = 0; i < v; i++) {
//         for(int j = 0; j < e; j++) {
//             std::cout << matrix[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }
//
// void generateMatrix(const int v, const int e, const std::string &fileName) {
//     auto matrix = new int[v][e];
//
// };

int main() {
    // int verticesNumber, edgesNumber;
    // getGraphInfo('test.txt', verticesNumber, edgesNumber);
    // displayMatrix(verticesNumber, edgesNumber, matrix[]);

    mainMenu();

    return 0;
}
