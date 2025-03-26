#include "fonctions.hpp"

int main(){
    std::vector<int> numbers;

    remplirVect(numbers, 5, 0, 100);

    afficheVect(numbers);

    int val;
    std::cout << "Entrez une valeur a chercher : ";
    std::cin >> val;

    if(find(numbers, val)){
        std::cout << "La valeur " << val << " a ete trouvee." << std::endl;
    } else {
        std::cout << "La valeur " << val << " n'a pas ete trouvee." << std::endl;
    }

    return 0;
}