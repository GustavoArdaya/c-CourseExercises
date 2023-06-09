#include <iostream>
#include <string>

using namespace std;

int main () {

    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "};
    string key      {"mnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl"};

    string original_message {};
    string encoded_message {};
    string decoded_message {};
    char confirmation {};
    bool looping {true};

    cout << "Please enter message for encryption: ";
    getline(cin, original_message);

    // for (size_t i = 0; i < original_message.length(); i++) {
    //     int index {};
    //     index = alphabet.find(original_message.at(i));        
    //     encoded_message += key.at(index);
    // }

    for (char c : original_message) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            char new_char {key.at(position)};
            encoded_message += new_char;
        } else {
            encoded_message += c;
        }

    }
    cout << "\nYour encrypted message is: " << encoded_message << endl;

    while (looping) {
        cout << "Do you want to decrypt it back? (Y/N): ";
        cin >> confirmation;        

        if (confirmation == 'y' || confirmation == 'Y') {
            cout << "y selected";
            
            // for (size_t i = 0; i < encoded_message.length(); i++) {
            //     int index {};
            //     index = key.find(encoded_message.at(i));
            //     decoded_message += alphabet.at(index);                
            // }
            for (char c : encoded_message) {
                size_t position = key.find(c);
                if (position != string::npos) {
                    char new_char {alphabet.at(position)};
                    decoded_message += new_char;
                } else {
                    decoded_message += c;
                }
            }
            cout << "\nYour decrypted message is: " << decoded_message << endl;
            
            if (original_message == decoded_message) {
                cout << "Decryption successful! The message is back to normal" << endl;
                looping = false;
            }
        } else if (confirmation == 'n' || confirmation == 'N') {
            cout << "Ok! Bye!" << endl;
            looping = false;
        } else cout << "Not a valid option. Try again!" << endl;
    }
    return 0;
}