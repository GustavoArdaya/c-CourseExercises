#include <iostream>
#include <stack>
#include <vector>
#include <list>


// no iterators! So to display stack you must empty it
template <typename T>
void display(std::stack<T> s) { // its passing value by value, making a copy and not destroying original in the process of displaying it
    std::cout << "[ ";
    while (!s.empty()) {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main () {

    std::stack <int> s;
    std::stack <int, std::vector<int>> s1;
    std::stack <int, std::list<int>> s2;
    std::stack <int, std::deque<int>> s3;

    for (int i : {1,2,3,4,5})
        s.push(i);
    display(s);

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while (!s.empty())
        s.pop();
    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    s.push(10);
    display(s);

    s.top() = 100;
    display(s);

    return 0;
}