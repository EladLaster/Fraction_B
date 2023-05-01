#ifndef FRACTION
#define FRACTION

#include <iostream>

namespace ariel{

class Fraction{

private:
    int numerator;
    int denominator;

public:
Fraction();
Fraction(float other);
Fraction(int numerator, int denominator);
void reduce();
int getNumerator() const;
int getDenominator() const;
Fraction operator+(const Fraction& other) const;
Fraction operator+(const float& other) const;
friend Fraction operator+(const float& flo, const Fraction& fraction);
Fraction operator-(const Fraction& other) const;
Fraction operator-(const float& other) const;
friend Fraction operator-(const float& flo, const Fraction& fraction);
Fraction operator*(const Fraction& other) const;
Fraction operator*(const float& other) const;
friend Fraction operator*(const float& flo, const Fraction& fraction);
Fraction operator/(const Fraction& other) const;
Fraction operator/(const float& other) const;
friend Fraction operator/(const float& flo, const Fraction& fraction);
bool operator==(const Fraction& other) const;
bool operator==(const float& other) const;
friend bool operator==(const float& flo, const Fraction& fraction);
bool operator>(const Fraction& other) const;
bool operator>(const float& other) const;
friend bool operator>(const float& flo, const Fraction& fraction);
bool operator<(const Fraction& other) const;
bool operator<(const float& other) const;
friend bool operator<(const float& flo, const Fraction& fraction);
bool operator>=(const Fraction& other) const;
bool operator>=(const float& other) const;
friend bool operator>=(const float& flo, const Fraction& fraction);
bool operator<=(const Fraction& other) const;
bool operator<=(const float& other) const;
friend bool operator<=(const float& flo, const Fraction& fraction);
Fraction& operator++();
const Fraction operator++(int);
Fraction& operator--();
const Fraction operator--(int);
friend std::ostream& operator<<(std::ostream& ost, const Fraction& fraction);
friend std::istream& operator>>(std::istream& ist, Fraction& fraction);

};
}
#endif