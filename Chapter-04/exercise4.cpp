#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    unsigned char c = 0;
    unsigned int code = 0;

    cout << "\nPlease enter a decimal character code:  ";
    cin >> code;

    c = code;

    cout << "\nCharacter codes"
         << "\n  decimal:     " << setw(3) << dec << code
         << "\n  octal:       " << setw(3) << oct << code
         << "\n  hexadecimal: " << setw(3) << hex << code
         << endl;

    return 0;

}