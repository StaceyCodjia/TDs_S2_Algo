#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };
//Exo 1 - 2
    std::cout << "f1 = "<< f1 << std::endl;
    std::cout << " f2 = "<< f2 << std::endl;

 {
    Fraction f3 = f1 + f2;
    std::cout << "f1 + f2 = " << f3 << std::endl;

    f3 = f1 - f2;
    std::cout << "f1 - f2 = " << f3 << std::endl;

    f3 = f1 * f2;
    std::cout << "f1 * f2 = " << f3 << std::endl;

    f3 = f1 / f2;
    std::cout << "f1 / f2 = " << f3 << std::endl;
}
 //Exo 3
    if (f1 == f2) {
        std::cout << "f1 egal a f2" << std::endl;
    } else {
        std::cout << "f1 n'est pas egal a f2" << std::endl;
    }

    if (f1 != f2) {
        std::cout << "f1 est different de f2" << std::endl;
    } else {
        std::cout << "f1 = f2" << std::endl;
    }


// Exo 4

    if (f1 < f2) {
        std::cout << "f1 < f2" << std::endl;
    } else {
        std::cout << "f1 pas inferieur a f2" << std::endl;
    }

    if (f1 <= f2) {
        std::cout << "f1 <=  f2" << std::endl;
    } else {
        std::cout << "f1 > f2" << std::endl;
    }

    if (f1 > f2) {
        std::cout << "f1 > f2" << std::endl;
    } else {
        std::cout << "f1 pas superieur a f2 " << std::endl;
    }

    if (f1 >= f2) {
        std::cout << "f1 >= f2 " << std::endl;
    } else {
        std::cout << "f1 < f2 " << std::endl;
    }

// Exo 5
    
    Fraction f3 = f1;
    f3 += f2;
    std::cout << "f1 += f2 = " << f3 << std::endl;

    f3 = f1;
    f3 -= f2;
    std::cout << "f1 -= f2 = " << f3 << std::endl;

    f3 = f1;
    f3 *= f2;
    std::cout << "f1 *= f2 = " << f3 << std::endl;

    f3 = f1;
    f3 /= f2;
    std::cout << "f1 /= f2 = " << f3 << std::endl;


    // Exo 6
    float floatNumber = static_cast<float>(f1);
    std::cout << "f1 en format de type float = " << floatNumber << std::endl;
        return 0;
    }