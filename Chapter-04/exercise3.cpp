#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    long number = 0;
    int count = 0;
    double price = 0.0;

    cout << "\nPlease enter article description. \n";
    cout << "Article number:    ";
    cin >> number;

    cout << "Number of pieces:      ";
    cin >> count;

    cout << "Price per piece:       ";
    cin >> price;

    cout << "\n\tArticle Number     Quantity    Price per piece ";

    cout << "\n\t"
         << setw(8)  << number
         << setw(16) << count
         << setw(16) << price << " Dollar" << endl;

    return 0;
}