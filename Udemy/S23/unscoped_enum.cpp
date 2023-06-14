#include <iostream>
#include <vector>
#include <string>

// used for test1

enum Direction {North, South, East, West}; // values cannot be reused in different enum


std::string direction_to_string(Direction direction) {
    std::string result;
    switch (direction) {
        case North:
            result = "North"; break;
        case South:
            result = "South"; break;
        case East:
            result = "Eastt"; break;
        case West:
            result = "West"; break;
        default:
            result = "Unknown direction";
    }
    return result;
}

void test1() {
    std::cout << "\nTest1 ==============================" << std::endl;

    Direction direction {North};
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = West;
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = Direction(1);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = Direction(100);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = static_cast<Direction>(100);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

}

// used for test2
enum Grocery_Item {Milk, Bread, Apple, Orange};

// overloaded << operator for Grocery_Item enum
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_Item) {

    switch (grocery_Item) {
        case Milk: 
            os << "Milk"; break;
        case Bread: 
            os << "Bread"; break;
        case Apple: 
            os << "Apple"; break;
        case Orange: 
            os << "Orange"; break;
        default:
            os << "Invalid item";    
    }
    return os;
}

// validator for grocery item
bool is_valid_grocery_item(Grocery_Item grocery_item) {

    switch (grocery_item) {
        case Milk:           
        case Bread:
        case Apple:
        case Orange: 
            return true;
        default:
            return false;    
    }
}

void display_grocery_list(const std::vector<Grocery_Item> &grocery_list) {

    std::cout << "Grocery List" << "\n============================" << std::endl;
    int invalid_item_count{0};
    int valid_item_count{0};
    for (Grocery_Item Grocery_Item : grocery_list) {
        
        std::cout << Grocery_Item << std::endl;

        if (is_valid_grocery_item(Grocery_Item))
            valid_item_count++;
        else
            invalid_item_count++;
    }

    std::cout << "============================" << std::endl;
    std::cout << "Valid items: " << valid_item_count << std::endl;
    std::cout << "Invalid items: " << invalid_item_count << std::endl;
    std::cout << "Total items: " << valid_item_count + invalid_item_count << std::endl;
}

void test2() {
    std::cout << "\nTest2 ==============================" << std::endl;

    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);

    int Helicopter {1000};

    shopping_list.push_back(Grocery_Item(Helicopter));
    shopping_list.push_back(Grocery_Item(0));

    display_grocery_list(shopping_list);
}

// for test 3
enum State {Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence{Abort, Hold, Launch};

std::istream &operator>>(std::istream &is, State &state) {

    std::underlying_type_t<State> user_input;
    is >> user_input;
    
    switch (user_input) {
        case Engine_Failure:
        case Inclement_Weather:
        case Nominal:
        case Unknown:
            state = State(user_input); break;
        default:
            std::cout << "User input is not a valid launch state." << std::endl;
            state = Unknown;    
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, Sequence &sequence) {

    switch (sequence) {
        case Abort:
            os << "Abort"; break;
        case Hold:
            os << "Hold"; break;
        case Launch:
            os << "Launch"; break;
    }
    return os;
}

void initiate(Sequence sequence) {
    std::cout << "Initiate " << sequence << " sequence!" << std::endl;
}

void test3() {
    std::cout << "\nTest3 ==============================" << std::endl;

    State state;
    std::cout << "Launch state: ";
    std::cin >> state;          // with overloaded >> operator

    switch (state) {
        case Engine_Failure:
        case Unknown:
            initiate(Abort); break;
        case Inclement_Weather:
            initiate(Hold); break;
        case Nominal:
            initiate(Launch); break;
    }
}

int main() {

    test1();
    test2();
    test3();
    

    return 0;

}