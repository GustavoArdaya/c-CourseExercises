#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    double x1 = 0.123456;
    double x2 = 23.987;
    double x3 = -123.456;

    cout << left << setw(15) << x1 << "." << endl;
    cout << right << setw(12) << setprecision(2) << x2 << "." << endl;
    cout << scientific << setw(10) << setprecision(4) << x3 << "." << endl;

    return 0;
}