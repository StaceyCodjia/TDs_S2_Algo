#include "fonctions.hpp"

int main(){
    std::vector<Card> cards = get_cards(100);
    std::unordered_map<Card, int> card_counts;

    for (const Card& card : cards) {
        card_counts[card]++;
    }

    for (auto const& card : card_counts) {
        std::cout << card_name(card.first) << " : " << card.second << '\n';
    }

    return 0;
}