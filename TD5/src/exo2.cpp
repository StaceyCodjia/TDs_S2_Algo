#include "fonctions.hpp"

int main(){
  //1
    std::vector<float> expected_insect_probabilities = probabilities_from_count(expected_insect_counts);
    std::vector<std::pair<Insect, int>> observations = get_insect_observations(10000, expected_insect_probabilities, 40);

    std::unordered_map<Insect, int> filtered_insect_counts;
//2
    for (const auto& observation : observations) {
        Insect insect_type = observation.first;
        int insect_count = observation.second;
        filtered_insect_counts[insect_type] += insect_count;
    }
//3
   std::vector<int> filtered_insect_counts_vector;
    filtered_insect_counts_vector.resize(filtered_insect_counts.size());
   for (const auto& insect : filtered_insect_counts) {
       for (int i = 0; i < insect_values.size(); i++) {
          if (insect.first == insect_values[i]) {
            filtered_insect_counts_vector[i] = insect.second;
            //std::cout << filtered_insect_counts_vector.size() << std::endl;
            break;
          }
       }
    }
    std::vector<float> my_observation_probabilities = probabilities_from_count(filtered_insect_counts_vector);
    // std::cout << "Probabilities from counts: ";
    // for (float prob : my_observation_probabilities) {
    //     std::cout << prob << " ";
    // }

//4

for (size_t i = 0; i < insect_values.size(); i++) {
    float difference = std::abs(expected_insect_probabilities[i] - my_observation_probabilities[i]);
    std::string result = "OK";
    if (difference > 0.01)
        result = "PAS OK";
    std::cout << insect_to_string.at(insect_values[i])  << " : " << expected_insect_probabilities[i] << " VS " << my_observation_probabilities[i] << " : " << result << std::endl;
}

    // Uncomment the following line to test the function with the expected counts
    // std::vector<float> expected_probabilities =
    //probabilities_from_count(filtered_insect_counts)
    return 0;
}