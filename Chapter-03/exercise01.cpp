//raices cuadradas
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double x1 = 4.0, x2 = 12.25, x3 = 0.0121;

    cout << "\n   Number    \t Square Root" << endl;
    cout << "\n    " << x1 << "    \t  "  << sqrt(x1)
         << "\n    " << x2 << "    \t  "  << sqrt(x2)
         << "\n    " << x3 << "    \t  "  << sqrt(x3) << endl;
    
    cout << "\nType a number whose square root is to be computed. ";
    cin >> x1;

    cout << "\n   Number    \t Square Root" << endl;
    cout << "\n    " << x1 << "    \t  "  << sqrt(x1) << endl;

    return 0;
}