#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <cmath>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), 
    std::istream_iterator<std::string>()); 
}
int main(){

    std::string npi;
    std::cout << "Entrez une expression en notation polonaise inversee : ";
    std::getline(std::cin, npi); 
}