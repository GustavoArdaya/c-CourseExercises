#include <iostream>
#include <vector>

//For test1
enum class Grocery_Item { Milk = 350, Bread = 250, Apple = 132, Orange = 100 }; // "class" indicates it's scoped enum

// overloaded stream insertion operator

std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item) {
    std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_item);
    switch (grocery_item) {
        case Grocery_Item::Milk:
            os << "Milk"; break;
        case Grocery_Item::Bread:
            os << "Bread"; break;
        case Grocery_Item::Apple:
            os << "Apple"; break;
        case Grocery_Item::Orange:
            os << "Orange"; break;
        default:
            os << "Invalid item";
    }
    os << " : " << value;
    return os;
}

bool is_valid_grocery_item(Grocery_Item grocery_item)
{
	switch (grocery_item) {
	    case Grocery_Item::Milk:  
        case Grocery_Item::Bread:
        case Grocery_Item::Apple:
        case Grocery_Item::Orange:
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

void test1() {
    std::cout << "\nTest1 ==============================" << std::endl;

    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Grocery_Item::Apple);
    shopping_list.push_back(Grocery_Item::Milk);
    shopping_list.push_back(Grocery_Item::Orange);

    int helicopter {1000};

    shopping_list.push_back(Grocery_Item(helicopter));
    shopping_list.push_back(Grocery_Item(350));

    display_grocery_list(shopping_list);
}

class Player {
    friend std::ostream &operator<<(std::ostream &os, const Player &p);
public:
    enum class Mode {Attack, Defense, Idle};
    enum class Direction {North, South, East, West};
    
    Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North):
        name{name}, mode{mode}, direction{direction} {}

    std::string get_name() const {
        return name;
    }
    void set_name(std::string name) {
        this->name = name;
    }
    
    Mode get_mode() const {return mode; }
    void set_mode(Mode mode) {
        this->mode = mode;
    }

    Direction get_direction() const {return direction; }
    void set_direction(Direction direction) {
        this->direction = direction;
    }
private:
    std::string name;
    Mode mode;
    Direction direction;
};

std::string get_player_mode(Player::Mode mode) {
    std::string result;
    switch (mode) {
        case Player::Mode::Attack:
            result = "Attack"; break;
        case Player::Mode::Defense:
            result = "Defense"; break;
        case Player::Mode::Idle:
            result = "Idle"; break;
    };
    return result;
}

std::string get_player_direction(Player::Direction direction) {
    std::string result;
    switch (direction) {
        case Player::Direction::North:
            result = "North"; break;
        case Player::Direction::South:
            result = "South"; break;
        case Player::Direction::East:
            result = "East"; break;
        case Player::Direction::West:
            result = "West"; break;
    };
    return result;
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
    os  << "Player name:        " << p.get_name() << "\n"
        << "Player mode:        " << get_player_mode(p.mode) << "\n"
        << "Player direction:   " << get_player_direction(p.direction) << std::endl;
    return os;
}

void test2() {
    std::cout << "\nTest1 ==============================" << std::endl;

    Player p1 {"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
    Player p2 {"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3 {"Sephiroth", Player::Mode::Idle, Player::Direction::South};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

}

int main() {

    test1();
    test2();


    return 0;
}