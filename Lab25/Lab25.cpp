#include <iostream>
using namespace std;

class Fraction {
    int a;
    int b;
public:
    Fraction(int n, int m) {
        a = n;
        if (m == 0) { cout << "На ноль делить нельзя! "; exit(1); };
        b = m;
    }

    operator double() {
        return double(a) / double(b);
    }

    void print() const {
        cout << a << "/" << b;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    Fraction fraction1(3, 2);
    Fraction fraction2(1, 2);
    Fraction fraction3(5, 8);

    cout << "Дроби:" << endl;
    fraction1.print(); cout << ", ";
    fraction2.print(); cout << ", ";
    fraction3.print(); cout << endl;

    cout << "Результаты :" << endl;
    cout << "Дробь 1 + Дробь 2: " << fraction1 + fraction2 << endl;
    cout << "Дробь 2 - Дробь 3: " << fraction2 - fraction3 << endl;
    cout << "Дробь 3 * Дробь 1: " << fraction3 * fraction1 << endl;
    cout << "((Дробь 2 >= Дробь 3) && (Дробь2 <= Дробь1)): " << ((fraction2 <= fraction3) && (fraction2 <= fraction1)) << endl;
    return 0;
}
