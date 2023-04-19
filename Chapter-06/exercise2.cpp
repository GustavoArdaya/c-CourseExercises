#include <iostream>
#include <iomanip>

using namespace std;

int main () {

    cout    << "\n\n"
            << "  ******* MULTIPLICATION TABLE *******  "
            << endl;

    for (int h = 0; h <= 10; h++) {
        if (h == 0) {
                cout << setw(3) << "     ";
            } else {
                cout << setw(5) << h;
        }
    }
    cout << "\n  ------------------------------------------------------\n";
    
    cout << setfill(' ');
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {  
            if (j == 0) {
                cout << setw(3) <<  i << " |";
            } else {         
            cout << setw(5) << i * j;
            }
        }
        cout << "\n";
    }
    cout << "\n\n";
    return 0;
}