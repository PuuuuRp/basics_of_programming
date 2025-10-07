#include <iostream>
#include <cmath>

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    // Задание 1
    int N;
    int sum = 0, mx = 0, num = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        if (a % 3 != 0 && a % 5 != 0 && a % 7 != 0) {
            sum += a;
            mx = mx <= a ? a : mx;
            num = mx == a ? i : num;
        }
    }
    if (sum == 0) {
        cout << "В последовательности не найдены подходящие значения" << endl << endl;
    }
    else {
        cout << "Сумма значений последовательности: " << sum << endl;
        cout << "Максимальное значение последовательности: " << mx << endl;
        cout << "Номер максимального значения: " << num << endl << endl;
    }

    // Задание 2
    int n;
    cin >> n;
    if (abs(n) >= 1000) {
        cout << "Некорректное число";
        return 0;
    }

    int copy_n = n;
    int count = 0;
    do {
        count += 1;
        n /= 10;
    } while (n);

    if (count == 3) {
        cout << "Кол-во индексов: " << count << endl;
        cout << "Первая цифра: " << abs(copy_n) / 100;
    }
    else if (count == 2) {
        cout << "Кол-во индексов: " << count << endl;
        cout << "Первая цифра: " << abs(copy_n) / 10;
    }
    else {
        cout << "Кол-во индексов: " << count << endl;
        cout << "Первая цифра: " << abs(copy_n);
    }

    return 0;
}