#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <random>

// Exo 1
struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;

    void insert(int value);

    int height() const;

    void delete_children();

    void display_infix() const;

    std::vector<Node const*> prefix() const;
    std::vector<Node const*> postfix() const;

    Node*& most_left(Node*& node);

    int min() const;
    int max() const;

};

Node* create_node(int value);
void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);
