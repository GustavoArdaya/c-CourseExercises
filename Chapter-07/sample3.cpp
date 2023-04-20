#include <iostream>
#include <cctype>
using namespace std;

int main () {
    char c;
    long    nChar = 0,      //counts all characters
            nConv = 0;      //counts converted characters

    while ( cin.get(c) ) 
    {   ++nChar;
        if ( islower(c))
        {   c = toupper(c);
            ++nConv;

        }
        cout.put(c);        // outputs character
    }
    clog    << "\nTotal of characters:      " << nChar
            << "\nTotal of converted characters: " << nConv
            << endl;
    return 0;
}