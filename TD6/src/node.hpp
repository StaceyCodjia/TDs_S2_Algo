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
};

Node* create_node(int value);