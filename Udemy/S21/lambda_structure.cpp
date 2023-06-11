#include <iostream>
#include <vector>

void print_if(std::vector<int> nums, bool (*predicate) (int)) {
        for (int i : nums)
            if (predicate(i))
                std::cout << i << " ";
        std::cout << std::endl;
    }

int main() {

    [] () {std::cout << "Hola" << std::endl;}();
    [] (int x) { std::cout << x << std::endl;}(1); 
    auto l = [] () { std::cout << "I'm 'l'" << std::endl;};
    l();
    auto l_par = [] (int x) {std::cout << "I print " << x << std::endl;};
    l_par(10);

    auto ret_lam = [] (int x, int y) -> int { return x + y; };
    std::cout << ret_lam(2,3) << std::endl;

    int x {10};

    auto l_point = [] (int *x) { std::cout << *x << std::endl;};

    l_point(&x);

    auto l_byref = [] (int *x, int increase) {*x += increase;};
    l_byref(&x, 5);
    l_point(&x);

    auto auto_l = [] (auto x) {std::cout << x << std::endl;};
    auto_l(100);
    auto_l(100.5f);
    auto_l('A');
    auto_l("Hola");

    // to return function from funtion: Example
    // std::function<void(int)> example() {
    //      return [] (int x) {std::cout << x;};
    //}

    // predicate is a function that takes parameters and returs boolean
    // predicate lambda:
    std::vector<int> nums {1,2,3};

    print_if(nums, [] (auto x) { return x % 2 == 0;});
    print_if(nums, [] (auto x) { return x % 2 != 0;});
    


    return 0;
}