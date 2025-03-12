#pragma once

struct Fraction {
    int numerator { 0 };
    int denominator { 1 };

    void display();
    void operator+=(Fraction const& f);
    void operator-=(Fraction const& f);
    void operator*=(Fraction const& f);
    void operator/=(Fraction const& f);
    float to_float() const;
    operator float() const;
};

Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);