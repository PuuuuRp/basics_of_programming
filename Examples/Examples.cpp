#include <iostream>

int main() {

    int* arr = (int*)calloc(2, sizeof(int));

    std::cout << sizeof(arr) << std::endl;
    std::cout << sizeof(*arr) << std::endl;

    free(arr);

    return 0;
}