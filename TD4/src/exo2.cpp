#include "fonctions.hpp"

int main(){
    std::string phrase;
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, phrase);

    int length = lengthWord(phrase);
    std::cout << "La longueur du premier mot est : " << length << std::endl;
    std::vector<std::string> mots = split_string(phrase);
    std::cout << "Les mots de la phrase sont :" << std::endl;
    for (int i = 0; i < mots.size(); i++){
        std::string mot = mots[i];
        std::cout << mot << std::endl;
    }
    return 0;
}