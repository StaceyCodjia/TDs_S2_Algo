#include "fonctions.hpp"


int main(){

    std::vector<int> vec = {1, 2, 3, 3, 6, 14, 12, 15};
    int value = 15;

    //std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int value = 10;

    int index = search(vec, value);

    if(index != -1){
        std::cout << "Valeur trouvee a l'indice : " << index << std::endl;
    } else {
        std::cout << "Valeur non trouvee" << std::endl;
    }
    return 0;
}