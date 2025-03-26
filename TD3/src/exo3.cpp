#include "fonctions.hpp"
#include "ScopedTimer.hpp"

int main(){

    std::vector<int> array {generate_random_vector(1000)};
    std::sort(array.begin(), array.end());


    {
        ScopedTimer timer(" quick_sort ");
        quick_sort(array);
    }

    {
        ScopedTimer timer(" bubble_sort ");
        bubble_sort(array);
    }

    {
        ScopedTimer timer(" std::sort ");
        std::sort(array.begin(), array.end());
    }
}

// On remarque que le std::sort (0.1185ms) est beaucoup plus rapide que le bubble_sort (19.5612ms).
// Et légèrement plus rapide que le quick_sort (0.123ms).
//Le bubble sort est lent car il fait beaucoup de comparaisons et d’échanges, 
//tandis que std::sort est optimisé avec des algorithmes avancés qui réduisent ces opérations.