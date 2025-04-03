#include "fonctions.hpp"


//Exo 1
size_t folding_string_hash(std::string const& s, size_t max) {
    size_t sum = 0;
    for (char c : s) {
        sum += static_cast<size_t>(c); 
    }
    return sum % max; //Permet de ramener la valeur de hachage dans l'intervalle [0, max-1]
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash = 0;
    size_t prime = 31; 
    for (char c : s) {
        hash = (hash * prime + static_cast<size_t>(c)) % max;
    }
    return hash; 
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    
}
