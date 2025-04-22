#include "fonctions.hpp"


//Exo 1
size_t folding_string_hash(std::string const& s, size_t max) {
    size_t sum = 0;
    for (char c : s) {
        sum += static_cast<size_t>(c); // Convertit le caractère en entier
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

//Exo 3
//1
bool operator==(const Card& Card1, const Card& Card2) {
    return Card1.kind == Card2.kind && Card1.value == Card2.value;
}

//2
size_t Card::hash() const {
    return static_cast<size_t>(kind) * 31 + static_cast<size_t>(value);
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + std::to_string(card_value);
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'J';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}