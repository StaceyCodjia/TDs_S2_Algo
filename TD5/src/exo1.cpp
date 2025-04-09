#include "fonctions.hpp"

int main(){
    // std::string phrase = "coucou";
    // size_t max = 100;
    // size_t hashValue = folding_string_hash(phrase, max);
    // std::cout << "Hash = " << hashValue << std::endl;

    std::string str = "hello";
    size_t p = 31; 
    size_t m = 1e9 + 9;

    size_t hashValue = polynomial_rolling_hash(str, p, m);
    std::cout << "Hash = " << hashValue << std::endl;


    // std::string str1 = "IMAC";
    // std::string str2 = "MICA";
    // size_t max = 100;

    // size_t hash1 = folding_string_ordered_hash(str1, max);
    // size_t hash2 = folding_string_ordered_hash(str2, max);

    // std::cout << "Hash IMAC = " << hash1 << std::endl;
    // std::cout << "Hash MICA = " << hash2 << std::endl;
    return 0;
}