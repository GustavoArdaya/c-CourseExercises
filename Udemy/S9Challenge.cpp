#include <iostream>
#include <vector>

using namespace std;

int main () {

    bool quit_selected {false};
    char choice {};
    vector <int> number_list {2, 14, 6, 1, -4, 0, 7};

    cout << "\nThis is a program to perform a series of operations on a list of integers." <<endl;

    while (!quit_selected) {
        cout << "Please select an option from the menu: \n" << endl;
        cout << "P. Print numbers\nA. Add a number\nM. Display the mean of the numbers\nS. Display the smallest number\n";
        cout << "L. Display the largest number\nQ. Quit\n" << endl;
        cin >> choice;
        if (choice == 'p' || choice == 'P') {
            cout << endl;
            for (auto num : number_list) {
                cout << num << " ";
            }
            cout << endl;
        }
        else if (choice == 'a' || choice == 'A') {
            int number_to_add {};
            cout << "\nEnter integer to add to list: ";
            cin >> number_to_add;
            number_list.push_back(number_to_add);
            cout << number_to_add << " added to list" << endl;
            cout << "List is now: ";
            for (auto num : number_list) {
                cout << num << " ";
            }

        }
        else if (choice == 'm' || choice == 'M') {
            int sum {};
            for (auto num : number_list) {
                sum += num;
            }
            cout << "\nThe mean of the numbers is " << sum / number_list.size() << endl;
        }
        else if (choice == 's' || choice == 'S') {
            int min = number_list.at(0);
            for (auto num : number_list) {
                if (num < min) min = num;
            }
            cout << "\nThe smallest number is " << min << endl;
        }
        else if (choice == 'l' || choice == 'L') {
            int max = number_list.at(0);
            for (auto num : number_list) {
                if (num > max) max = num;
            }
            cout << "\nThe largest number is " << max << endl;
        }
        else if (choice == 'q' || choice == 'Q') {
            cout << "\nBye!" << endl;
            quit_selected = true;
        }
        else cout << "\nNot a valid option. Please try again.\n";
    }
    return 0;
}