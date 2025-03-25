#include "fonctions.hpp"

int main(){

    std::vector<int> vec = {4, 2, 2, 8, 3, 3, 1};
    int max = 8;

    std::cout << "Avant tri : " << std::endl;
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    counting_sort(vec, max);

    std::cout << "Apres tri : " << std::endl;
    for (int num : vec) {
        std::cout << num << " ";
    }

    return 0;
}