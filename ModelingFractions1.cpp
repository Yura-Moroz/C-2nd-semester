#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
};

int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction::Fraction(int numerator, int denominator) {
    // Ensure the sign is stored in the numerator
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    // Simplify the fraction
    int gcd = calculateGCD(abs(numerator), denominator);
    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;
}

string Fraction::toString() {
    int wholePart = numerator / denominator;
    int remainder = abs(numerator) % denominator;
    string sign = (numerator < 0) ? "-" : "";

    if (wholePart != 0 && remainder != 0) {
        return sign + to_string(wholePart) + " " + to_string(remainder) + "/" + to_string(denominator);
    }
    else if (wholePart != 0) {
        return sign + to_string(wholePart);
    }
    else {
        return sign + to_string(remainder) + "/" + to_string(denominator);
    }
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main(void) {
    int num, den;
    std::string input;
    std::getline(std::cin, input);

    // Parse input and get numerator and denominator
    size_t slashPos = input.find('/');
    if (slashPos != std::string::npos) {
        num = stoi(input.substr(0, slashPos));
        den = stoi(input.substr(slashPos + 1));
    }
    else {
        // Handle invalid input
        cout << "Invalid input format." << endl;
        return 0;
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    return 0;
}