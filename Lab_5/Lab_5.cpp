#include <iostream>
#include <vector>
#include <limits>

void ReadArr(int n, int arr[]) {
    std::cout << "Исп. ф-ия для ввода данных для массива." << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << std::endl;
}

void WriteArr(int n, int arr[]) {
    std::cout << "Исп. ф-ия для вывода массива." << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool ChechNumers(int n, int arr[]) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {

    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int n = 11;
    while (n < 1 || n > 10) {
        std::cout << "Введите, сколько значений будет вводиться (от 1 до 10)." << std::endl;
        std::cin >> n;
    }
    int arr[10];
    ReadArr(n, arr);


    return 0;
}