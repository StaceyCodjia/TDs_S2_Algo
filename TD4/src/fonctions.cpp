#include "fonctions.hpp"


//Exo 1
void remplirVect(std::vector<int>& vect, int taille, int min, int max){
    std::srand(std::time(0));
    for(int i = 0; i < taille; i++){
        vect.push_back(std::rand() % (max - min + 1) + min);
    }
}

void afficheVect(const std::vector<int>& vec){
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool find (const std::vector<int>& vec, int val){
    auto it = std::find(vec.begin(), vec.end(), val);
    return it != vec.end();
}

int occurences(const std::vector<int>& vec, int val){
    return std::count (vec.begin(), vec.end(), val);
}

void tri(std::vector<int>& vec){
    return std::sort(vec.begin(), vec.end());
}

int somme(const std::vector<int>& vec){
    return std::accumulate(vec.begin(), vec.end(), 0);
}