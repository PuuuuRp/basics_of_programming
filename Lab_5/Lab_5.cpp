#include <iostream>
#include <cmath>

int p1(int a, int b) { // Для двух чисел
    int cnt_b = 0;
    int copy_b = b;
    while (b) {
        cnt_b += 1;
        b /= 10;
    }
    return a * pow(10, cnt_b) + copy_b;
}

int p1(int a) { // Для одного числа
    return -a;
}

void p2(int a, int b, int c) {
    float p = (a + b + c) / 2.0;
    std::cout << "\nПолученный полупериметр: " << p << std::endl;

    float geron = sqrt(p * (p - a) * (p - b) * (p - c));
    std::cout << "Полученная площадь по теореме Герона: " << geron;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::cout << p1(1, 12);

    const int N = 6;
    int arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Введите номер пункта (1 или 2): ";
    int x;
    std::cin >> x;
    if (x == 1) {
        // Подсчёт количества ненулевывх значений и сортировка
        int cnt = 0;
        for (int i = 0; i < 2; ++i) {
            if (arr[i] == 0) {
                for (int j = i + 1; j < 3; ++j) {
                    if (arr[j] != 0) {
                        std::swap(arr[i], arr[j]);
                        cnt += 1;
                        break;
                    }
                }
            }
            else cnt += 1;
        }
        if (cnt == 2) {
            std::cout << p1(arr[0], arr[1]);
        }
        else if (cnt == 1) {
            std::cout << p1(arr[0]);
        }
        else std::cout << "Некорректно введённые данные!";
    }
    else if (x == 2) {
        p2(arr[3], arr[4], arr[5]);
    }
    else std::cout << "Номер пункта не найден!";


    return 0;
}