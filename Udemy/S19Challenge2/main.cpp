#include <iostream>
#include <fstream>
#include <iomanip>

int main() {

    std::ifstream in_file;
    std::string name;
    std::string response;
    int grade {};
    int sumGrade {};
    int sumStudents {};
    std::string key;

    in_file.open("../responses.txt");

    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    in_file >> key;
    
    std::cout << std::endl;
    std::cout   << std::setw(15) << std::left << "Student"
                << std::setw(5)  << std::right << "Grade" << std::endl;
    std::cout   << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout   << std::setfill(' ');

    while (!in_file.eof()) {
        grade = 0;
        in_file >> name >> response; 
        sumStudents++;
        for (int i = 0; i < key.length(); i++) {
            if (key.at(i) == response.at(i)) {
                grade++;
            }
        }        
        std::cout   << std::setw(15) << std::left << name
        << std::setw(5)  << std::right << grade << std::endl;
        sumGrade += grade;
    }

    double avg = static_cast<double> (sumGrade) / sumStudents;

    std::cout   << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout   << std::setfill(' ');
    std::cout   << std::setw(15) << std::left << "Average score"
    << std::setw(5)  << std::right << avg << std::endl;
    std::cout << std::endl;

    return 0;
}