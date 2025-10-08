#include <iostream>
#include <cmath>

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    // Задание 1
    int N;
    int sum = 0, mx = 0, num = 0;
    cin >> N;
    if (N != 0) {
        for (int i = 1; i <= N; ++i) {
            int a;
            cin >> a;
            if (a % 3 != 0 && a % 5 != 0 && a % 7 != 0) {
                sum += a;
                mx = mx <= a ? a : mx;
                num = mx == a ? i : num;
            }
        }
        if (mx == 0) {
            cout << "В последовательности не найдены подходящие значения" << endl << endl;
        }
        else {
            cout << "Сумма значений последовательности: " << sum << endl;
            cout << "Максимальное значение последовательности: " << mx << endl;
            cout << "Номер максимального значения: " << num << endl << endl;
        }
    }
    else cout << "Задана пустая последовательность!" << endl;


    // Задание 2
    int n;
    do {
        cin >> n;
        if (abs(n) >= 1000) {
            cout << "Введите корректное число (по модулю меньше 1000)!" << endl;
        }
    } while (abs(n) >= 1000);

    int copy_n = n;
    int count = 0;
    do {
        count += 1;
        n /= 10;
    } while (n);

    cout << "Кол-во разрядов: " << count << endl;
    cout << "Первая цифра: " << abs(copy_n) / pow(10, count - 1);
    

    return 0;
}