#include <iostream>
#include <cmath>
#include "Fraction.hpp"
#include <climits>

using namespace std;
namespace ariel{

    Fraction::Fraction(){
        this->numerator=0;
        this->denominator=1;
    }
    Fraction floatToFraction(float num) 
    {
        int numerator = num * 1000;
        int denominator = 1000;
        return Fraction(numerator, denominator);
    }

    float fraction_to_float(Fraction num) {
    float result = (float)num.getNumerator() / (float)num.getDenominator();
    return roundf(result * 1000.0) / 1000.0;
    }

    void is_overflow(Fraction num){

        if(num.getDenominator()>=INT_MAX||num.getDenominator()<=INT_MIN||num.getNumerator()>=INT_MAX||num.getNumerator()<=INT_MIN)
            throw overflow_error("error : overflow");
    }

    Fraction::Fraction(float other){
        Fraction temp = floatToFraction(other);
        this->numerator=temp.getNumerator();
        this->denominator=temp.getDenominator();
    }

    Fraction::Fraction(int numerator, int denominator) {

    if (denominator == 0)
        throw invalid_argument("Error: divide by zero");
    this->numerator = numerator;
    this->denominator = denominator;

    if (this->denominator < 0) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }

    reduce();
}
    void Fraction::reduce() {
        int gcd = __gcd(abs(this->numerator), abs(this->denominator));
        this->numerator /= gcd;
        this->denominator /= gcd;
        if (this->denominator < 0) {
            this->numerator = -numerator;
            this->denominator = -denominator;
        }
    }

    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        is_overflow(other);
        is_overflow(*this);
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction Fraction::operator+(const float& other) const {
        Fraction temp = floatToFraction(other);
        return *this + temp;
    }

    Fraction operator+(const float& flo, const Fraction& fraction) {
        Fraction temp = floatToFraction(flo);
        return fraction + temp;
    }

    Fraction Fraction::operator-(const Fraction& other) const {
    long n = (long(this -> numerator) * other.getDenominator()) - (long(other.getNumerator()) * this -> denominator);
    long d = long(this->denominator) * other.getDenominator();
     if (n > INT_MAX || d > INT_MAX ||  n < INT_MIN || d < INT_MIN){
        throw std::overflow_error ("error : overflow");
    }
    int num = (this-> numerator * other.getDenominator()) - (other.getNumerator() * this -> denominator);
    int den = this -> denominator * other.getDenominator();
    return Fraction(num, den);
    }

    Fraction Fraction::operator-(const float& other) const {
        Fraction temp = floatToFraction(other);
        return *this - temp;
    }

    Fraction operator-(const float& flo, const Fraction& fraction) {
        Fraction temp = floatToFraction(flo);
        return temp - fraction;
    }

    Fraction Fraction::operator*(const Fraction& other) const {
    long n = long(this->numerator) * other.getNumerator();
    long d = long(this->denominator) * other.getDenominator();
     if (n > INT_MAX || d > INT_MAX ||  n < INT_MIN || d < INT_MIN){
        throw overflow_error ("error : overflow");
    }
    int num = (this->numerator * other.getNumerator());
    int den = this ->denominator * other.getDenominator();
    return Fraction(num, den);
}

    Fraction Fraction::operator*(const float& other) const {
        Fraction temp = floatToFraction(other);
        return *this * temp;
    }

    Fraction operator*(const float& flo, const Fraction& fraction) {
        Fraction temp = floatToFraction(flo);
        return fraction * temp;
    }

    Fraction Fraction:: operator/(const Fraction& other) const {
        if (other.getNumerator() == 0){
        throw std::runtime_error("error : divide by zero");
    }
    long n = long(this->numerator) * other.getDenominator();
    long d = long(this->denominator) * other.getNumerator();
     if (n > INT_MAX || d > INT_MAX ||  n < INT_MIN || d < INT_MIN){
        throw overflow_error ("error : overflow");
    }
    int num = this -> numerator * other.denominator;
    int den = this -> denominator * other.getNumerator();
    return Fraction(num, den);
    }

    Fraction Fraction:: operator/(const float& other) const {
        Fraction temp = floatToFraction(other);
        return *this / temp;
    }

    Fraction operator/(const float& flo, const Fraction& fraction) {
        Fraction temp = floatToFraction(flo);
        return temp / fraction;
    }

    bool Fraction::operator==(const Fraction& other) const {
    if (this ->numerator == 0 && other.getNumerator() == 0){
        return true;
    }
    double n = round(double(this->numerator)/this->denominator * 1000) / 1000.0;
    double d = round(double(other.getNumerator())/other.getDenominator() * 1000) / 1000.0;
    if (n == d){
        return true;
    }
    return false;
    }

    bool Fraction:: operator==(const float& other) const {
        float temp = fraction_to_float(*this);
        return other == temp;
    }

    bool operator==(const float& flo, const Fraction& fraction) {
        float temp = fraction_to_float(fraction);
        return flo == temp;
    }
    bool Fraction::operator>(const Fraction& other) const {
        is_overflow(other);
        is_overflow(*this);
        float result1 = (float)numerator / denominator;
        float result2 = (float)other.numerator/other.denominator;
        return result1>result2;
    }
    bool Fraction::operator>(const float& other) const {
        Fraction temp = floatToFraction(other);
        return *this > temp;
    }
    bool operator>(const float& flo, const Fraction& fraction) {
        Fraction temp = floatToFraction(flo);
        return temp > fraction;
    }

    bool Fraction::operator<(const Fraction& other) const {
        is_overflow(other);
        is_overflow(*this);
        float result1 = (float)numerator / denominator;
        float result2 = (float)other.numerator / other.denominator;
        return result1 < result2;
    }

    bool Fraction::operator<(const float& other) const {
        Fraction temp = floatToFraction(other);
        return *this < temp;
    }

    bool operator<(const float& flo, const Fraction& fraction) {
        Fraction temp = floatToFraction(flo);
        return temp < fraction;
    }
    bool Fraction::operator>=(const Fraction& other) const {
        is_overflow(other);
        is_overflow(*this);
        return (*this > other) || (*this == other);
    }
    bool Fraction::operator>=(const float& other) const {
        return (*this > other) || (*this == other);
    }

    bool operator>=(const float& flo, const Fraction& fraction) {
        return (fraction < flo) || (fraction == flo);
    }

    bool Fraction::operator<=(const Fraction& other) const {
        is_overflow(other);
        is_overflow(*this);
        return (*this < other) || (*this == other);
    }

    bool Fraction::operator<=(const float& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator<=(const float& flo, const Fraction& fraction) {
        return (fraction > flo) || (fraction == flo);
    }

    Fraction& Fraction::operator++() {
        Fraction tmp = Fraction(denominator,denominator);
        *this = *this + tmp;
        reduce();
        return *this;
    }

    const Fraction Fraction::operator++(int) {
        Fraction tmp = *this;
        operator++();
        return tmp;
    }

    Fraction& Fraction::operator--() {
        Fraction tmp = Fraction(denominator,denominator);
        *this = *this - tmp;
        reduce();
        return *this;
    }

    const Fraction Fraction::operator--(int) {
        Fraction tmp = *this;
        operator--();
        return tmp;
    }

    ostream& operator<<(ostream& ost, const Fraction& fraction) {
        ost << fraction.getNumerator() << "/" << fraction.getDenominator();
        return ost;
    }

    istream& operator>>(istream& ist, Fraction& fraction) {
        int n, d;
        ist >> n >> d;

        if (ist.fail()) {
        throw runtime_error("error : invalid input");
    }
        if (d == 0) {
            throw runtime_error("error : divide by zero");
    }
        fraction = Fraction(n, d);
        return ist;
    }
}