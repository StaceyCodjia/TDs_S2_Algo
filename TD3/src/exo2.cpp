#include "fonctions.hpp"



int main(){

    std::vector<int> vec {6,4,2,1,3,5};

    std::cout << "Avant tri : ";
    affichage(vec);

    quick_sort(vec, 0, vec.size() - 1);

    std::cout << "Apres tri : ";
    affichage(vec);
    return 0;
}
