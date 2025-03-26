#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec);

// Exo 1
void bubble_sort(std::vector<int> & vec);

// Exo 2
size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<int> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<int> & vec);
void affichage(const std::vector<int>& vec);

// Exo 3
std::vector<int> generate_random_vector(size_t const size, int const max = 100);

// Exo 4
int search(std::vector<int> const& vec, int const value);

//Pour aller plus loin
void counting_sort(std::vector<int> & vec, int const max);