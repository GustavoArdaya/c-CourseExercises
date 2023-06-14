#include <iostream>
#include <vector>
#include <algorithm>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
private:
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age)
        : name {name}, age {age} {}
    Person(const Person &p): name{p.name}, age {p.age} {}
    ~Person() = default;

    std::string get_name() const { return name; };
    void set_name(std::string name) { this->name = name;}; 
    int get_age() const { return age; };
    void set_age(int age) { this-> age = age;};
    bool operator<(const Person &rhs) const {
        return this-> age < rhs.age;
    }

    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }

    auto change_person1() { return [this] (std::string new_name, int new_age) {name=new_name; age=new_age;};} // because of syntax between [ ], "this." is not needed to access fields
    auto change_person2() { return [=] (std::string new_name, int new_age) {name=new_name; age=new_age;};} // version with [=] is deprecated in c++20, since it captures by reference actually and not by value as it usually is
    auto change_person3() { return [&] (std::string new_name, int new_age) {name=new_name; age=new_age;};}
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << "[Person: " << p.name << " - " << p.age << "]";
    return os;
}

int global_x{1000};

void test1() {
    std::cout << "\nTest1 ==============================" << std::endl;

    int local_x{100};

    auto l = [local_x] () {
        std::cout << local_x << std::endl;      // copy of local x
        std::cout << global_x << std::endl;
    };
    l();
}

void test2() {
    std::cout << "\nTest2 ==============================" << std::endl;

    int x{100};

    auto l = [x] () mutable {   // with mutable keyword compiler allows change, but it doesnt show outside because of pass by value
        
        x += 100;
        std::cout << x << std::endl;   
    };

    l();
    std::cout << x << std::endl;   // first time x changes to 200

    l();
    std::cout << x << std::endl;   // second time x changes to 300 inside lambda even though it wasnt changed outside lambda!
                                   // Capture of states only happens the first time. (Class is created with static value)
}                                   

void test3() {
    std::cout << "\nTest3 ==============================" << std::endl;

    int x{100};

    auto l = [&x] () mutable {  // it doesnt create a copy, so values are changed outside also
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;
}

void test4() {
    std::cout << "\nTest4 ==============================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=] () mutable {   // [=] captures every variable by value (default). Since z is not used inside lambda is not captured!
    x += 100;
    y += 100;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    };

    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

void test5() {
    std::cout << "\nTest5 ==============================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&] () {   // [&] makes capture by reference
        x += 100;
        y += 100;
        z += 100;

        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test6() {
    std::cout << "\nTest6 ==============================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=, &y] () mutable {
        x += 100;
        y += 100;
        z += 100;

        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

}

void test7() {
    std::cout << "\nTest7 ==============================" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&, x, z] () mutable {
        x += 100;
        y += 100;
        z += 100;

        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test8() {

    std::cout << "\nTest8 ==============================" << std::endl;

    Person person("Larry", 18);

    std::cout << person << std::endl;

    // with default capture [this]:
    auto change_person1 = person.change_person1(); // assign method to variable
    change_person1("Moe", 30);
    std::cout << person << std::endl;

    // default capture [=]:
    auto change_person2 = person.change_person2();
    change_person2("Curly", 25);
    std::cout << person << std::endl;

    // default capture [&]:
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << person << std::endl;
}

// for test9
class Lambda {
        private:
            int y;
        public:
        Lambda(int y) : y{y} {};

        void operator() (int x) const { // useful to create function of class instance
            std::cout << x + y << std::endl;
        };
    };
void test9() {
    std::cout << "\nTest9 ==============================" << std::endl;

    int y {100};

    Lambda lambda1(y);
    auto lambda2 = [y] (int x) {std::cout << x + y << std::endl;};

    lambda1(200);
    lambda2(200);    
}

class People {
    std::vector<Person> people;
    int max_people;

public:
    People(int max = 10) : max_people{max} {}
    People(const People &p) = default;
    void add(std::string name, int age) {
        people.emplace_back(name, age);
    }
    void set_max_people(int max) {
        max_people = max;
    }
    int get_max_people() const {
        return max_people;
    }

    std::vector<Person> get_people(int max_age) {
        std::vector<Person> result;
        int count{0};
        std::copy_if(people.begin(),
                     people.end(),
                     std::back_inserter(result),
                     [this, &count, max_age] (const Person &p) 
                        { return p.get_age() > max_age && ++count <= max_people;});
        return result;
    }
};

void test10(){
    std::cout << "\nTest10 ==============================" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);

    auto result = friends.get_people(17);
    std::cout << std::endl;

    for (const auto &p: result)
        std::cout << p << std::endl;

    friends.set_max_people(3);

    result = friends.get_people(17);

    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
    
    result = friends.get_people(50);
    std::cout << std::endl;

    for (const auto &p: result)
        std::cout << p << std::endl;
}


int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}

