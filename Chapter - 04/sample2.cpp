#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string label;
    double price;

    cout << "\nPlease enter an article label: ";

    cin >> setw(16);
    cin >> label;

    cin.sync(); // libera el buffer y resetea los flags (como setw en este caso)
    cin.clear(); // 

    cout << "\nEnter the price of the article: ";
    cin >> price;

    cout << fixed << setprecision(2)
         << "\nArticle:"
         << "\n  Label:  " << label
         << "\n  Price:  " << price << endl;
    return 0;
}