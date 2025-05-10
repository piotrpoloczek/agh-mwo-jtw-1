#include <iostream>
#include "rational/rational.h"  // Update path if needed

int main() {
    Rational r2(2, 11), r3(1, -3), r5(18, 6);

    Rational res1 = 3 + r2 * r3;
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);

    std::cout << 3 << " + " << r2 << " * " <<  r3 << " = " << res1 << std::endl;
    std::cout << "(" << 3 << " + " << r2 << ")" << " * " <<  r3 << " = " << res2 << std::endl;
    std::cout << 3 << " + " << r3 << " * " << "(" << r2 << " + " << 2 << ")" << "/"
              << "(" << r5 << " - " << r3 << ")" << " = " << res3 << std::endl;

    return 0;
}
