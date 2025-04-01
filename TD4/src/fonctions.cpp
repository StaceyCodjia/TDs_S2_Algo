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

//Exo 2
int lengthWord(const std::string& phrase){
    auto const is_space = [](char letter){ return letter == ' '; };
    auto it = std::find_if(phrase.begin(), phrase.end(), is_space);
    return std::distance(phrase.begin(), it);
}

std::vector<std::string> split_string(const std::string& phrase) {
    std::vector<std::string> mots;
    auto const is_space = [](char letter) { return letter == ' '; };

    auto start = phrase.begin();
    while (start != phrase.end()) {
        start = std::find_if_not(start, phrase.end(), is_space);

        auto end = std::find_if(start, phrase.end(), is_space);

        if (start != end) {
            mots.push_back(std::string(start, end));
        }
        start = end;
    }

    return mots;
}

//Exo 3
bool palindrome(const std::string& str) {
    return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}

//Exo facultatif
int sommeCarres(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0, [](int sum, int val) {
        return sum + val * val;
    });
}