#include <iostream>
#include <memory>
#include <vector>

class Test {
// friend std::ostream &operator<<(std::ostream &os, const Test &test);

private:
    int data;
public: 
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
int get_data() const { return data;}
~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }



};

// std::ostream &operator<<(std::ostream &os, const Test &test) {
//     os << "[Test: " << test.data;
//     return os;
// }

int main () {

    // Test *t1 = new Test {1000};
    // delete t1;

    std::unique_ptr<Test> t1 {new Test{1000}};
    std::unique_ptr<Test> t2 = std::make_unique<Test>(2000);            // does not use new. Modern C++
    
    // you're not allowed to copy (with = assignment) but you can move it with std::move

    std::unique_ptr<Test> t3;
    t3 = std::move(t1);     // this moves t1 pointer into t3, so t1 becomes a null pointer
    if (!t1)                // t3 is now "owner" of previus t1 address
        std::cout << "t1 is nullptr" << std::endl;

    // std::vector<std::unique_ptr<Test>> tests;

    // tests.push_back(t2);
    // tests.push_back(t3);

    // for (const auto &test : tests) {
    //     std::cout << *test << std::endl;
    // }

    return 0;
}