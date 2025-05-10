#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

/*
 * Rational.h
 *
 * A class for representing and manipulating rational numbers as fractions.
 * This class enables exact arithmetic by avoiding floating-point precision errors.
 *
 * Key Applications:
 *  - Computer Algebra Systems: symbolic computation with exact values
 *  - Educational Tools: accurate fraction operations for teaching math
 *  - Financial Calculations: avoids rounding issues in currency and interest
 *  - Geometry & CAD: precise ratio-based computations in modeling
 *  - Simulations: deterministic behavior with exact rational step sizes
 *  - Compiler/Interpreter internals: simplifies expressions with full precision
 *
 * This is especially useful in domains where rounding errors can accumulate
 * and lead to incorrect results, unlike with float/double types.
 */
class Rational {
public:
    Rational(int numerator, int denominator = 1);
    ~Rational() {}
    Rational(const Rational& copy);

    Rational& operator=(const Rational& other);
    Rational& operator=(int i);

    int numerator() const { return numer; }
    int denominator() const { return denom; }

    static Rational normalize(const Rational& other);
    static Rational normalized(int numerator, int denominator);

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    Rational operator+() const;
    Rational operator-() const;

    bool operator==(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;

    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);

private:
    int numer;
    int denom;
    void initialize(int numerator, int denominator);
    static int gcd(int a, int b);
};

Rational operator+(const Rational& r, int i);
Rational operator+(int i, const Rational& r);
Rational operator-(const Rational& r, int i);
Rational operator-(int i, const Rational& r);
Rational operator*(const Rational& r, int i);
Rational operator*(int i, const Rational& r);
Rational operator/(const Rational& r, int i);
Rational operator/(int i, const Rational& r);

#endif
