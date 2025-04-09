#include "fonctions.hpp"


//Exo 1
size_t folding_string_hash(std::string const& s, size_t max) {
    size_t sum = 0;
    for (char c : s) {
        sum += static_cast<size_t>(c); 
    }
    return sum % max; //Permet de ramener la valeur de hachage dans l'intervalle [0, max-1]
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash = 0;
    size_t prime = 31; 
    for (char c : s) {
        hash = (hash * prime + static_cast<size_t>(c)) % max;
    }
    return hash; 
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash = 0;
    size_t power = 1; 

    for (char c : s) {
        hash = (hash + (static_cast<size_t>(c) * power) % m) % m;
        power = (power * p) % m;
    }

    return hash;
}

//Exo 2

std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t const number_of_observations,
    std::vector<float> const& insect_probabilities,
    unsigned int const seed)
{
    // Create a random engine with a given seed
    std::default_random_engine random_engine{seed};

    auto rand_insect_index { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { rand_insect_index() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        // If we have already seen the same insect, increment the count on the last observation
        if(!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts){
        std::vector<float> probabilities;
        int total_count = 0;
    
        for (int i=0; i < counts.size(); i++) {
            int count = counts[i];
            total_count += count;
        }
    
        if (total_count == 0) {
            return probabilities;
        }
    
        for (int count : counts) {
            probabilities.push_back(static_cast<float>(count) / total_count);
        }
    
        return probabilities;
    }
