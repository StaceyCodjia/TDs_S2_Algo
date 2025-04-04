#include "fonctions.hpp"


int main(){
    std::string npi;
    std::cout << "Entrez votre npi : ";
    std::getline(std::cin, npi); 
    std::vector<std::string> tokens = split_string(npi);

    for (int i = 0; i < tokens.size(); i++){
        std::string token = tokens[i];
        if (is_floating(token)){
            std::cout << "Nombre : " << token << std::endl;
        } else {
            std::cout << "Operateur : " << token << std::endl;
        }
    }

    std::cout << "Resultat : " << npi_evaluate(tokens) << std::endl;
    return 0;
}