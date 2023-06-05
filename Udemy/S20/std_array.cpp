#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

void display(const std::array<int, 5> &arr) {
    std::cout << "[ ";
    for (auto &e : arr) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {

    std::cout << "\nTest1 ==============================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2);          // containing garbage as not previously initialized

    arr2 = {10,20,30,40,50};

    display(arr1);
    display(arr2);

    std::cout << "The size of arr1 is " << arr1.size() << std::endl;
    std::cout << "The size of arr2 is " << arr2.size() << std::endl;

    arr1[0] = 1000;         // no bounds checking
    arr1.at(1) = 2000;      // does bounds checking
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;
    std::cout << "Back of arr2: " << arr2.back() << std::endl;
}

void test2() {
    std::cout << "\nTest2 ==============================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};
    std::array<int, 5> arr2 {10,20,30,40,50};

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);

}

void test3() {
    std::cout << "\nTest3 ==============================" << std::endl;

    std::array<int, 5> arr1 {1,2,3,4,5};

    int *ptr =arr1.data();
    std::cout << ptr << std::endl;
    *ptr = 10000;

    display(arr1);

}

void test4() {
    std::cout << "\nTest4 ==============================" << std::endl;
    std::array<int, 5> arr1 {2,1,4,5,3};
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);

}

void test5() {
    std::cout << "\nTest5 ==============================" << std::endl;
    std::array<int, 5> arr1 {2,1,4,5,3};

    std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end()); // returns iterator to element
    auto max_num = std::max_element(arr1.begin(), arr1.end()); 

    std::cout << "min: " << *min_num << ", max: " << *max_num << std::endl; 
}

void test6() {
    std::cout << "\nTest6 ==============================" << std::endl;
    std::array <int, 5> arr1 {2,1,3,3,5};

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());

    if (adjacent != arr1.end())
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else
        std::cout << "No adjacent elements found" << std::endl;
}

void test7() {
    std::cout << "\nTest7 ==============================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};

    // uses #include <numeric>
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

void test8() {
    std::cout << "\nTest8 ==============================" << std::endl;
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};

    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found number 3: " << count << " times" << std::endl;
}

void test9() {
    std::cout << "\nTest9 ==============================" << std::endl;
    std::array <int, 10> arr1 {1,2,3,50,60, 70, 80, 200, 300, 400};

    int count = std::count_if(arr1.begin(), arr1.end(), 
                                [] (int x) { return x > 10 && x < 200;});

    std::cout << "Found " << count << " numbers between 10 and 200" << std::endl;
}

int main () {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}