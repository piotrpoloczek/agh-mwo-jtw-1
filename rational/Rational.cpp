#include "rational.h"
#include <stdexcept>

Rational::Rational(int numerator, int denominator) {
    initialize(numerator, denominator);
}

Rational::Rational(const Rational& copy) : numer(copy.numer), denom(copy.denom) {}

Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        numer = other.numer;
        denom = other.denom;
    }
    return *this;
}

Rational& Rational::operator=(int i) {
    numer = i;
    denom = 1;
    return *this;
}

void Rational::initialize(int n, int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    int g = gcd(n, d);
    numer = d < 0 ? -n / g : n / g;
    denom = std::abs(d / g);
}

int Rational::gcd(int a, int b) {
    return b == 0 ? std::abs(a) : gcd(b, a % b);
}

Rational Rational::normalize(const Rational& r) {
    return Rational(r.numer, r.denom);
}

Rational Rational::normalized(int n, int d) {
    return Rational(n, d);
}

Rational Rational::operator+(const Rational& r) const {
    return Rational(numer * r.denom + r.numer * denom, denom * r.denom);
}

Rational Rational::operator-(const Rational& r) const {
    return Rational(numer * r.denom - r.numer * denom, denom * r.denom);
}

Rational Rational::operator*(const Rational& r) const {
    return Rational(numer * r.numer, denom * r.denom);
}

Rational Rational::operator/(const Rational& r) const {
    if (r.numer == 0) throw std::domain_error("Division by zero");
    return Rational(numer * r.denom, denom * r.numer);
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-numer, denom);
}

bool Rational::operator==(const Rational& r) const {
    return numer == r.numer && denom == r.denom;
}

bool Rational::operator>=(const Rational& r) const {
    return (numer * r.denom) >= (r.numer * denom);
}

bool Rational::operator<=(const Rational& r) const {
    return (numer * r.denom) <= (r.numer * denom);
}

bool Rational::operator>(const Rational& r) const {
    return (numer * r.denom) > (r.numer * denom);
}

bool Rational::operator<(const Rational& r) const {
    return (numer * r.denom) < (r.numer * denom);
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numer << "/" << r.denom;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    int n, d;
    char sep;
    is >> n >> sep >> d;
    if (sep == '/') r.initialize(n, d);
    else is.setstate(std::ios::failbit);
    return is;
}

// int overloads
Rational operator+(const Rational& r, int i) { return r + Rational(i); }
Rational operator+(int i, const Rational& r) { return Rational(i) + r; }
Rational operator-(const Rational& r, int i) { return r - Rational(i); }
Rational operator-(int i, const Rational& r) { return Rational(i) - r; }
Rational operator*(const Rational& r, int i) { return r * Rational(i); }
Rational operator*(int i, const Rational& r) { return Rational(i) * r; }
Rational operator/(const Rational& r, int i) { return r / Rational(i); }
Rational operator/(int i, const Rational& r) { return Rational(i) / r; }
