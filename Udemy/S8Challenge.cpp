#include <iostream>

using namespace std;

int main ()
{
    int number_of_cents {};

    int const dollar {100}, quarter {25}, dime {10}, nickel {5};

    cout << "Please enter a number of cents: ";
    cin >> number_of_cents;

    int number_of_dollars = number_of_cents / dollar;
    int number_of_quarters = (number_of_cents % dollar) / quarter;
    int number_of_dimes = (number_of_cents % dollar % quarter) / dime;
    int number_of_nickels = (number_of_cents % dollar % quarter % dime) / nickel;
    int number_of_pennies = number_of_cents % dollar % quarter % dime % nickel;

    cout << "Total number of coins: " << endl;
    cout << "Dollars:   " << number_of_dollars << endl;
    cout << "Quarters:  " << number_of_quarters << endl;
    cout << "Dimes:     " << number_of_dimes << endl;
    cout << "Nickels:   " << number_of_nickels << endl;
    cout << "Pennies:   " << number_of_pennies << endl;
    cout << endl;

    return 0;

}