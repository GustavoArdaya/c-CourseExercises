#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // for std::iota

//for_each
void test1() {
    std::cout << "\nTest1 ==============================" << std::endl;

    std::vector<int> nums {10,20,30,40,50};

    std::for_each(nums.begin(), nums.end(), [] (int num) {
        std::cout << num << " ";
    });
}

//is_permutation (predicate lambda)
void test2() {
    std::cout << "\nTest2 ==============================" << std::endl;

    struct Point {
        int x;
        int y;
    };

    Point pt1{1,2};
    Point pt2{4,3};
    Point pt3{3,5};
    Point pt4{3,1};

    std::vector<Point> triangle1 {pt1, pt2, pt3};
    std::vector<Point> triangle2 {pt2, pt3, pt1};
    std::vector<Point> triangle3 {pt1, pt2, pt4};

    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [](Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
        })
    )
        std::cout << "Triangle1 and Triangle2 are equivalent!" << std::endl;
    else
        std::cout << "Triangle1 and Triangle2 are NOT equivalent!" << std::endl;

    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [](Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
        })
    )
        std::cout << "Triangle1 and Triangle3 are equivalent!" << std::endl;
    else
        std::cout << "Triangle1 and Triangle3 are NOT equivalent!" << std::endl;    
}

// transform
void test3() {
    std::cout << "\nTest3 ==============================" << std::endl;

    std::vector<int> test_scores {93,88,75,68,65};
    int bonus_points {5}; // to be captured in lambda

    std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(), 
        [bonus_points] (int score) { return score += bonus_points;});
    
    for (int score : test_scores)
        std::cout << score << " ";
}

// remove_if
void test4() {
    std::cout << "\nTest4 ==============================" << std::endl;

    std::vector<int> nums {1,2,3,4,5};

    nums.erase(
        std::remove_if(
            nums.begin(), nums.end(), [] (int num) {
                return num % 2 == 0;
            }
        ), nums.end()
    );

    for (int num : nums)
        std::cout << num << " ";
}

// used for test5
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
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << "[Person: " << p.name << " - " << p.age << "]";
    return os;
}

// sort
void test5() {
    std::cout << "\nTest5 ==============================" << std::endl;

    Person person1("Larry", 18);
    Person person2("Moe", 30);
    Person person3("Curly", 25);

    std::vector<Person> people {person1, person2, person3};

    std::sort(people.begin(), people.end(), [] (Person lhs, Person rhs) {
        return lhs.get_name() < rhs.get_name();
    });

    for (Person person : people)
        std::cout << person << std::endl;

    std::cout << std::endl;

    std::sort(people.begin(), people.end(), [] (Person lhs, Person rhs) {
        return lhs.get_name() > rhs.get_name();
    });

     for (Person person : people)
        std::cout << person << std::endl;

    std::cout << std::endl;
}

// function in between for test 6
// uses all_of
bool in_between(const std::vector<int> &nums, int start_value, int end_value) {
    bool result {false};
    result = std::all_of(nums.begin(), nums.end(), [start_value, end_value] (int value) {
        return value >= start_value && value <= end_value;
    });
    return result;
}

void test6() {
    std::cout << "\nTest6 ==============================" << std::endl;

    std::cout << std::boolalpha;

    std::vector<int> nums(10);
    std::iota(nums.begin(), nums.end(), 1); // iota increments values 

    for (int num : nums)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << in_between(nums, 50, 60) << std:: endl;
    std::cout << in_between(nums, 1, 10) << std:: endl;
    std::cout << in_between(nums, 5, 7) << std:: endl;
}

// for test 7
class Password_Validator1 {
    private:
        char restricted_symbol {'$'};
    public:
        bool is_valid(std::string password) {
            return std::all_of(password.begin(), password.end(), 
                [this] (char character) { return character != restricted_symbol;});
        }
};


class Password_Validator2 {
    private:
        std::vector<char> restricted_symbols {'!','$', '+'};
    public:
        bool is_valid(std::string password) {
            return std::all_of(password.begin(), password.end(), 
                [this] (char character) { 
                    return std::none_of(restricted_symbols.begin(), restricted_symbols.end(),
                        [character] (char symbol) {
                            return character == symbol;
                        });                
                }
            );
        }
}; 


void test7() {
    std::cout << "\nTest7 ==============================" << std::endl;

    //Password_Validator1
    std::string password {"holywood1$"};
    Password_Validator1 pv1;

    if (pv1.is_valid(password))
        std::cout << "Password " << password << " is valid!" << std::endl;
    else
        std::cout << "Password " << password << " is NOT valid!" << std::endl;

    password = "hollywood1";

    if (pv1.is_valid(password))
        std::cout << "Password " << password << " is valid!" << std::endl;
    else
        std::cout << "Password " << password << " is NOT valid!" << std::endl;

    //Password_Validator2

    password = "C++Rocks!";
	Password_Validator2 pv2;
	
	
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	
	password = "CPlusPlusRocks!";
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	
	password = "CPlusPlusRocks";
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
}

int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}