#include "fonctions.hpp"

bool is_sorted(std::vector<int> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

//Exo 1

void bubble_sort(std::vector<int> & vec){
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size()-1; j++){
            if (vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}

//Exo 2
size_t quick_sort_partition (std::vector<float> & vec, size_t left, size_t right, size_t const pivot){
    
    float pivot_value = vec[pivot];

    std::swap(vec[pivot], vec[right]); // On met le pivot à la fin

    size_t store_index = left; 

    for (size_t i = left; i < right; i++){
        if (vec[i] < pivot_value){
            std::swap(vec[i], vec[store_index]);
            store_index++;
        }
    }

    std::swap(vec[store_index], vec[right]); // On remet le pivot à sa place

    return store_index;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){

    if (left < right){
        size_t pivot = left + (right - left) / 2;
        pivot = quick_sort_partition(vec, left, right, pivot);
        if (pivot > 0){
            quick_sort(vec, left, pivot-1);
        }
        quick_sort(vec, pivot+1, right);
    }
}

void quick_sort(std::vector<float> & vec){
    quick_sort(vec, 0, vec.size()-1);
}

void affichage (const std::vector<float>& vec) {
    for (float num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

//Exo 3
std::vector<int> generate_random_vector(size_t const size, int const max) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

//Exo 4
int search(const std::vector<int>& vec, int value){
    int left = 0;
    int right = vec.size()-1;
    while (left <= right){
        int middle = left + (right - left) / 2;
        if (vec[middle] == value){
            return middle;
        }
        else if (vec[middle] < value){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    return -1;
}