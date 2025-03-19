#include "fonctions.hpp"



int main(){
    // Exo 1
    std::vector<int> array {6,4,2,1,3,5};
        std::cout << "Avant tri a bulle" << std::endl;
        if (is_sorted(array)) {
            std::cout << "Le tableau est trie" << std::endl;
        } else {
            std::cout << "Le tableau n'est pas trie" << std::endl;
        }

        bubble_sort(array);
        std::cout << "Apres tri a bulle" << std::endl;
        for (int i = 0; i < array.size(); i++){
            std::cout << array[i] << " ";
        }
    return 0;
    
}