#include <iostream>

using namespace std;

void print(const int *const array, size_t array_size);
int *apply_all(const int *const array1, size_t array1_size, const int *const array2, size_t array2_size);

int main() {

    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array1: ";
    print(array1,array1_size);

    cout << "Array2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size (array1_size * array2_size);
    cout << "result: ";
    print(results, results_size);

    delete [] results;
    cout << endl; 

    return 0;
}



void print(const int *const array, size_t array_size) {
    cout << "[";
    for (size_t i{0}; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]";
    cout << endl;
}

int *apply_all(const int *const array1, size_t array1_size, const int *const array2, size_t array2_size) {
    
    int *new_array {};
    new_array = new int[array1_size * array2_size];
    int index {};

    for (size_t i {0}; i < array1_size; i++) {
        for (size_t j {0}; j < array2_size; j++) {
            new_array[index] = array1[i] * array2[j];
            index++;
        }
    }
    return new_array; // This function dynamically allocates a new array in heap
}