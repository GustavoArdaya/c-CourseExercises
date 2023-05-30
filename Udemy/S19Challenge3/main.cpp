#include <iostream>
#include <fstream>
#include <string>

bool find_substring(const std::string &input, const std::string &text) {
    std::size_t found = text.find(input);
    if (found == std::string::npos)
        return false;
    else
        return true;
}

int main() {

    std::ifstream in_file;
    std::string line;
    std::string user_input;
    int match_count {};
    int total_count {};

    in_file.open("../romeoandjuliet.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::cout << "Enter a word to search in Shakespeare's play Romeo and Juliet: ";
    std::cin >> user_input;

    while (!in_file.eof()) {

        in_file >> line;
        total_count++;
        if (find_substring(user_input, line)) {
            match_count++;
        }
    }
    std::cout << total_count << " words were searched..." << std::endl;
    std::cout << "The word " << user_input << " appeared  " 
              << match_count << " times." << std::endl;

    return 0;    

}