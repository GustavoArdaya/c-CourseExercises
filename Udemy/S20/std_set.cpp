#include <iostream>
#include <set>
#include <algorithm>
#include <iterator> // for std::advance

class Person {

    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;

    public:

        Person() : name {"Unkwnown"}, age {0} {}
        Person(std::string name, int age) 
            : name {name}, age {age} {}
        bool operator<(const Person &rhs) const { // SET USES THIS OPERATOR!
            return this->age < rhs.age;
        }
        bool operator==(const Person &rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(const std::set<T> &s) {
    std::cout << "[ ";
    for (const auto &e : s) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1 ==============================" << std::endl;

    std::set<int> s1 {1, 4, 3, 5, 2};
    display(s1);

    s1 = {1,2,3,1,1,2,2,3,3,4,5};
    display(s1);

    s1.insert(0);
    s1.insert(10);

    display(s1);

    if (s1.count(10))
        std::cout << "10 is in the set" << std::endl;
    else
        std::cout << "10 is NOT in the set" << std::endl;
    
    auto it = s1.find(5);           // uses default set iterator that profits from organization logic
    if (it != s1.end())
        std::cout << "Found: " << *it << std::endl;

    s1.clear();

    display(s1);
}

void test2() {
    std::cout << "\nTest2 ==============================" << std::endl;

    std::set<Person> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };

    display(stooges);

    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Gus", 50);
    display(stooges);

    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it);

    display(stooges);

    it = stooges.find(Person("XXXX", 50));  // will remove James!
    if (it != stooges.end())
        stooges.erase(it);

    display(stooges);
}

void test3() {
    std::cout << "\nTest3 ==============================" << std::endl;

    std::set<std::string> s {"A", "B", "C"};
    display(s);

    auto result = s.insert("D");    // returns std::pair with iterator and boolean if succesful
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl; // since result is a pair, "first" returns first value (iterator)
    std::cout << "second: " << result.second << std::endl;  // second value of result (boolean)

    std::cout << std::endl;

    result = s.insert("A"); // since its already in set, it will return false in second
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl; // since "A" was already in set, iterator goes to that element
    std::cout << "second: " << result.second << std::endl;  

}

int main() {

    test1();
    test2();
    test3();


    return 0;
}