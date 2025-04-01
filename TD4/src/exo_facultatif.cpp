#include "fonctions.hpp"

int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    int resultat = sommeCarres(numbers);

    std::cout << "La somme des carres des elements est : " << resultat << std::endl;

    return 0;
}