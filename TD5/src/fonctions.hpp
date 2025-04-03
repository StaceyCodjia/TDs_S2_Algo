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

// Exo 1
size_t folding_string_hash(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);