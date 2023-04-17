#include <iostream>
#include <string>
using namespace std;

string header = "   --- Demonstrates Unformatted Input ---";

int main(){
    string word, rest;

    cout << header
         << "\n\nPress <return> to go on" << endl;

    cin.get(); //lee la siguiente linea sin asignarla a una variable aun

    cout << "\nPlease enter a sentence with several words!"
         << "\nEnd with <!> and <return>."
         << endl;

    cin >> word; // se graba en "word" lo que se grabo en cin
    getline( cin, rest, '!'); // Lee las siguientes hasta el signo de admiración (fuente, variable, caracter final)

    cout << "\nThe first word:  " << word
         << "\nRemaining text:  " << rest << endl;

    return 0;
}