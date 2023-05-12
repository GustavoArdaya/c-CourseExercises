#include <iostream>
#include <string>

using namespace std;

int main() {

    string provided {};

    cout << "Please enter a string of characters for Letter Pyramid :";
    cin >> provided;
    
    cout << "\n" << endl;
    
    for (int i = 1; i <= provided.length(); i++) {
        string lead (provided.length()-i, ' ');
        string row {};
        for (int j = 0; j < i; j++) {
            row += provided.at(j);
        }
        for (int k = i-1; k > 0; k--) {
            row += provided.at(k-1);
        }
        cout << lead << row << lead << endl;
    }

    return 0;
}