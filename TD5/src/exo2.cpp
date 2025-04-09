#include "fonctions.hpp"

int main(){
    // std::vector<int> counts = {10, 20, 30};
    // std::vector<float> probabilities = probabilities_from_count(counts);

    // std::cout << "Probabilitees = ";
    // for (float prob : probabilities) {
    //     std::cout << prob << " ";
    // }
    std::cout << std::endl;

    std::vector<float> insect_probabilities = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f, 1.1f};
    size_t number_of_observations = 10000;
    unsigned int seed = 42; 
    std::vector<std::pair<Insect, int>> observations = get_insect_observations(
        number_of_observations, insect_probabilities, seed);

    std::unordered_map<Insect, int> insect_counts;

    for (const auto& insect : insect_values) {
        insect_counts[insect] = 0;
    }

    for (const auto& observation : observations) {
        insect_counts[observation.first] += observation.second;
    }

    std::cout << "Nombre d'individus pour chaque insecte :" << std::endl;
    for (const auto& [insect, count] : insect_counts) {
        std::cout << "Insecte " << static_cast<int>(insect) << ": " << count << " individus" << std::endl;
    }

    return 0;
}