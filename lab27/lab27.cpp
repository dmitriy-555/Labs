#include <iostream>
#include <list>

using namespace std;

class Complex {
private:
    double a, b;
public:
    Complex(double z = 0.0, double y = 0.0) {
        a = z;
        b = y;
    }
    double i() {
        return b;
    }
    void print() {
        if (b < 0) cout << a << " " << b << "i";
        else if (b > 0) cout << a << " + " << b << "i";
        else cout << a;
        cout << endl;
    }
};

int main()
{
    list<Complex> list{
        Complex(1, 2),
        Complex(0.5, 6),
        Complex(9, -4),
        Complex(-4, 5.7),
        Complex(0, 0)
    };

    for (auto iter = list.begin(); iter != list.end();)
    {
        if ((*iter).i() < 0) {
            iter = list.erase(iter);
        }
        else {
            ++iter;
        }
    }

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        (*iter).print();
    }

    return 0;
}
