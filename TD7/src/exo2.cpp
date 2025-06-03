#include "fonctions.hpp"

int main(){
    
    std::vector<std::vector<float>> adjacency_matrix = {{1, 0, 4},
                                                        {0, 2, 0},
                                                        {8, 5, 1}};
    Graph::WeightedGraph graph1 = Graph::build_from_adjacency_matrix(adjacency_matrix);

    graph1.print_BFS(1);
    graph1.print_DFS(1);
}