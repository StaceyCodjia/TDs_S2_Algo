#include "fonctions.hpp"



int main(){

    std::vector<float> vec {6.0,4.0,2.0,1.0,3.0,5.0};

    std::cout << "Avant tri : ";
    affichage(vec);

    quick_sort(vec, 0, vec.size() - 1);

    std::cout << "Apres tri : ";
    affichage(vec);
    return 0;
}
