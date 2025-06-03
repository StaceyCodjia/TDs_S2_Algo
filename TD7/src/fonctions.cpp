#include "fonctions.hpp"

// Exo 1

void Graph::WeightedGraph::add_vertex(int const id){
    if (adjacency_list.find(id) != adjacency_list.end())
        return;
    adjacency_list[id] = {};
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
        add_vertex(from);
        add_vertex(to);
        adjacency_list[from].push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
    Graph::WeightedGraph graph{};
    
    for(std::size_t j {0}; j < adjacency_matrix.size(); j++){
        graph.add_vertex(j);
        std::vector<float> line{adjacency_matrix[j]};

        for(std::size_t i {0}; i < line.size(); i++)
            if (line[i] != 0.)
                graph.add_directed_edge(j, i, line[i]);
    }

    return graph;
}

// Exo 2

void Graph:: WeightedGraph::print_DFS(int const start) const{
    std::stack<int> to_visit{};
    std::set<int> visited;
    visited.insert(start);
    to_visit.push(start);
    while (!to_visit.empty()){
        int current = to_visit.top();
        auto edge_adjacent = *(adjacency_list.find(current));
        to_visit.pop();

        std::cout << current << std::endl;
        for (WeightedGraphEdge adjacent : std::get<1>(edge_adjacent)){
            if (!visited.contains(adjacent.to)){
                to_visit.push(adjacent.to);
                visited.insert(adjacent.to);
            }
        }
    }
}

void Graph:: WeightedGraph::print_BFS(int const start) const{
    std::queue<int> to_visit{};
    std::set<int> visited;
    visited.insert(start);
    to_visit.push(start);
    while (!to_visit.empty()){
        int current = to_visit.front();
        auto edge_adjacent = *(adjacency_list.find(current));
        to_visit.pop();

        std::cout << current << std::endl;
        for (WeightedGraphEdge adjacent : std::get<1>(edge_adjacent)){
            if (!visited.contains(adjacent.to)){
                to_visit.push(adjacent.to);
                visited.insert(adjacent.to);
            }
        }
    }
}