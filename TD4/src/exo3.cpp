#include "fonctions.hpp"

int main(){
        std::string str;
    
        std::cout << "Entrez un mot : ";
        std::getline(std::cin, str);
    
        if (palindrome(str)) {
            std::cout << str << " est un palindrome." << std::endl;
        } else {
            std::cout << str << " n'est pas un palindrome." << std::endl;
        }
    
        return 0;
}