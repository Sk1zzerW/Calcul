#include <iostream>
#include <stdexcept>

class Drobi {
private:
    int numerator;
    int denominator;

public:

    Drobi() : numerator(0), denominator(1) {}

    Drobi(int n, int d) {
        if (d == 0) {
            throw std::invalid_argument("Error");
        }
        numerator = n;
        denominator = d;
    }

    void input() {
        std::cout << "Enter first nmbr ";
        std::cin >> numerator;
        std::cout << "Enter second nmbr ";
        std::cin >> denominator;
        if (denominator == 0) {
            throw std::invalid_argument("Error");
        }
    }

    void display() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    int gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }

    Drobi operator+(const Drobi& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        Drobi result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }

    Drobi operator-(const Drobi& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        Drobi result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }

    Drobi operator*(const Drobi& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        Drobi result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }

    Drobi operator/(const Drobi& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Ділення на нуль неможливе!");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        Drobi result(newNumerator, newDenominator);
        result.simplify();
        return result;
    }
};

int main() {
    try {
        Drobi fraction1, fraction2;

        std::cout << "Enter first Drib:" << std::endl;
        fraction1.input();

        std::cout << "Enter second Drib:" << std::endl;
        fraction2.input();

        std::cout << "Plus: ";
        Drobi sum = fraction1 + fraction2;
        sum.display();

        std::cout << "Minus: ";
        Drobi diff = fraction1 - fraction2;
        diff.display();

        std::cout << "Multiply: ";
        Drobi prod = fraction1 * fraction2;
        prod.display();

        std::cout << "Divide: ";
        Drobi div = fraction1 / fraction2;
        div.display();
    }
    catch (const std::exception& e) {
        std::cerr << "Error " << e.what() << std::endl;
    }

    return 0;
}
