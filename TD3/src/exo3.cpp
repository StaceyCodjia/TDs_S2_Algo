#include "fonctions.hpp"
#include "ScopedTimer.hpp"

int main(){

    std::vector<int> array {generate_random_vector(1000)};
    std::sort(array.begin(), array.end());


    // {
    //     ScopedTimer timer(" quick_sort ");
    //     quick_sort(array);
    // }

    {
        ScopedTimer timer(" bubble_sort ");
        bubble_sort(array);
    }

    {
        ScopedTimer timer(" std::sort ");
        std::sort(array.begin(), array.end());
    }
}