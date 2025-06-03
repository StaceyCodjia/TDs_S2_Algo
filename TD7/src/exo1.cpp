#include "fonctions.hpp"

int main(){

    // Exo 1

    std::vector<std::vector<float>> matrix = {
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0}
    };

    Graph::WeightedGraph Graph1 = Graph::build_from_adjacency_matrix(matrix);

    Graph::WeightedGraph Graph2;

    for (int i = 0; i < 5; ++i) Graph2.add_vertex(i);
    Graph2.add_directed_edge(0, 1, 1);
    Graph2.add_directed_edge(0, 2, 3);
    Graph2.add_directed_edge(1, 5, 7);
    Graph2.add_directed_edge(0, 3, 4);
    Graph2.add_directed_edge(6, 7, 8);
    Graph2.add_directed_edge(9, 4, 0);

    std::cout << "Les graphes sont " << (Graph1 == Graph2 ? "pareils" : "differents") << std::endl ;
    return 0;
}