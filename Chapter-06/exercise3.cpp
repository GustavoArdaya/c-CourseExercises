#include<cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    unsigned int i, seed;

    cout << "\nPlease type an integer between 0 and 65535: ";
    cin >> seed;
    srand(seed); // "seeds" random function

    cout << "\n\n********* Random Numbers *********\n\n";

    for (i = 1; i <= 20; ++i) {
        cout    << setw(7) << i << ". Random number = "
                << setw(3) << (rand() % 100 + 1) << endl;
    }

    return 0;
}