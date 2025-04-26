#pragma once
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <memory>

struct SmartNode {
    int value;
    std::unique_ptr<SmartNode> left { nullptr };
    std::unique_ptr<SmartNode> right { nullptr };

    bool is_leaf() const;
    void insert(int value);

    size_t height() const;

    int min() const;
    int max() const;

    std::unique_ptr<SmartNode>& most_left(std::unique_ptr<SmartNode>& node);
};
std::unique_ptr<SmartNode> create_smart_node(int value);
void pretty_print_left_right(SmartNode const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(SmartNode const& node);
std::unique_ptr<SmartNode> create_smart_node(int value);
bool remove(std::unique_ptr<SmartNode>& node, int value);