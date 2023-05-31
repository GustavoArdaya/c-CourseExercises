#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {

    std::ifstream in_file {"../romeoandjuliet.txt"};
    std::ofstream out_file {"../romeoandjuliet_out.txt"};
    int line_num {1};

    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if (!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    std::string line {};

    while (std::getline(in_file, line)) {
        if (line.compare("") == 0) {
        out_file << std::setw(8) << "" << line << std::endl;    
        } else {
        out_file << std::setw(8) << std::left << line_num << line << std::endl;
        line_num++;    
        }
    }

    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();

    return 0;
}