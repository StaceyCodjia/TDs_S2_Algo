#include "fonctions.hpp"

int main(){
    std::vector<int> counts = {10, 20, 30};
    std::vector<float> probabilities = probabilities_from_count(counts);

    std::cout << "Probabilitees = ";
    for (float prob : probabilities) {
        std::cout << prob << " ";
    }
    std::cout << std::endl;

    return 0;
}