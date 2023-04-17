#include <iostream>
#include <string>
using namespace std;

string header = "   --- Demonstrates Unformatted Input ---";

int main(){
    string word, rest;

    cout << header
         << "\n\nPress <return> to go on" << endl;

    cin.get(); //lee la siguiente linea sin grabarla

    cout << "\nPlease enter a sentence with several words!"
         << "\nEnd with <!> and <return>."
         << endl;

    cin >> word; // Lee la primera palabra
    getline( cin, rest, '!'); // Lee las siguientes hasta el signo de admiración (metodo, variable, caracter final)

    cout << "\nThe first word:  " << word
         << "\nRemaining text:  " << rest << endl;

    return 0;
}