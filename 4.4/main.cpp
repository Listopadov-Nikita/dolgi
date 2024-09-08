#include <iostream>
#include "Rational.h"

using namespace std;

int main() {
    Rational r1, r2;
    cout << "input first rational (m/n): ";
    cin >> r1;
    cout << "input second rational (m/n): ";
    cin >> r2;

    cout << "first rational: " << r1 << endl;
    cout << "second rational: " << r2 << endl;

    Rational sum = r1 + r2;
    Rational difference = r1 - r2;
    Rational product = r1 * r2;
    Rational quotient = r1 / r2;

    cout << "Sum: " << sum << endl;
    cout << "Subtract: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Division: " << quotient << endl;

    if (r1 == r2)
        cout << "Rational are equal" << endl;
    else
        cout << "Rational are not equal" << endl;
  
    return 0;
}
