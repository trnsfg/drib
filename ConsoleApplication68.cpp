#include <iostream>
using namespace std;

class Drib {
private:
    int numerator;
    int denominator;

    int nsd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void Simplifying() {
        int divisor = nsd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Drib(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Error" << endl;
            denominator = 1;
        }
        Simplifying();
    }

    void setDrib(int num, int denom) {
        if (denom == 0) {
            cout << "Error" << endl;
            denom = 1;
        }
        numerator = num;
        denominator = denom;
        Simplifying();
    }

    void print() const {
        if (denominator == 1) {
            cout << numerator;
        }
        else {
            cout << numerator << "/" << denominator;
        }
    }

    Drib add(const Drib& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Drib(new_numerator, new_denominator);
    }

    Drib subtract(const Drib& other) const {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Drib(new_numerator, new_denominator);
    }

    Drib multiply(const Drib& other) const {
        return Drib(numerator * other.numerator, denominator * other.denominator);
    }

    Drib divide(const Drib& other) const {
        if (other.numerator == 0) {
            cout << "Error" << endl;
            return Drib(0, 1);
        }
        return Drib(numerator * other.denominator, denominator * other.numerator);
    }
};

int main() {
    Drib n1(1, 3);
    Drib n2(5, 10);

    Drib result_add = n1.add(n2);
    cout << "Addition: ";
    result_add.print();
    cout << endl;

    Drib result_sub = n1.subtract(n2);
    cout << "Subtraction: ";
    result_sub.print();
    cout << endl;

    Drib result_mul = n1.multiply(n2);
    cout << "Multiplication: ";
    result_mul.print();
    cout << endl;

    Drib result_div = n1.divide(n2);
    cout << "Division: ";
    result_div.print();
    cout << endl;

}
