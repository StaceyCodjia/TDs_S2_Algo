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
void remplirVect(std::vector<int>& vect, int taille, int min, int max);
void afficheVect(const std::vector<int>& vec);
bool find (const std::vector<int>& vec, int val);
int occurences(const std::vector<int>& vec, int val);
void tri(std::vector<int>& vec);
int somme(const std::vector<int>& vec);