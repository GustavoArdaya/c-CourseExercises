#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
    string line;
    int number = 0;

    while ( getline( cin, line))    // As long as a line
    {
        cout    << setw(5) << ++number << ": "
                << line << endl;
    }
    return 0;
}