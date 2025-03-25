#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>
//* Exo 2
void Fraction::display() {
    std::cout << numerator << "/" << denominator; 
}
std::ostream& operator<<(std::ostream& os, Fraction const& f){
    os <<  f.numerator << "/" << f.denominator;
    return os;
}

//* Exo 1
// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

Fraction operator+(Fraction f1, Fraction const& f2){
    f1 += f2;
    return f1;
}
// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

Fraction operator-(Fraction f1, Fraction const& f2){
    f1 -= f2;
    return f1;
}
// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

Fraction operator*(Fraction f1, Fraction const& f2){
    f1 *= f2;
    return f1;
}
// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }

Fraction operator/(Fraction f1, Fraction const& f2){
    f1 /= f2;
    return f1;
}

//* Exo 3
bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}
bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

//* Exo 4
bool operator< (Fraction const& f1, Fraction const& f2) {
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;      
}
bool operator <= (Fraction const& f1, Fraction const& f2){
    return f1 < f2 || f1 == f2;
}
bool operator > (Fraction const& f1, Fraction const& f2){
    return !(f1 <= f2);
}
bool operator >= (Fraction const& f1, Fraction const& f2){
    return !(f1 < f2);
}

//* Exo 5
void Fraction ::operator += (Fraction const& f){
    numerator = numerator*f.denominator + f.numerator*denominator;
    denominator = denominator* f.denominator;
    *this = simplify(*this);
}
void Fraction ::operator-=(Fraction const& f) {
       numerator = numerator * f.denominator - f.numerator * denominator,
       denominator = denominator* f.denominator;
       *this = simplify(*this);
}
void Fraction ::operator*=(Fraction const& f) {
    numerator = numerator * f.numerator,
    denominator = denominator* f.denominator;
    *this = simplify(*this);
}
void Fraction ::operator/=(Fraction const& f) {
    numerator = numerator * f.denominator,
    denominator = denominator* f.denominator;
    *this = simplify(*this);
}

//* Exo 6
float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}

//Pour aller plus loin
Fraction operator+(Fraction const& f, int const i) {
    return f + Fraction{i, 1};
}

Fraction operator+(int const i, Fraction const& f) {
    return Fraction{i, 1} + f;
}


Fraction operator-(Fraction const& f, int const i) {
    return f - Fraction{i, 1};
}

Fraction operator-(int const i, Fraction const& f) {
    return Fraction{i, 1} - f;
}


Fraction operator*(Fraction const& f, int const i) {
    return f * Fraction{i, 1};
}

Fraction operator*(int const i, Fraction const& f) {
    return Fraction{i, 1} * f;
}

Fraction operator/(Fraction const& f, int const i) {
    return f / Fraction{i, 1};
}

Fraction operator/(int const i, Fraction const& f) {
    return Fraction{i, 1} / f;
}