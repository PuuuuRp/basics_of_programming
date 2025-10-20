#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    // Задание №1
    const int N = 9;
    int arr[N];
    bool flag = false;
    // Заполнение массива
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
        // Нахождение в массиве числа, начинающегося с цифры 3
        if (!flag) {
            int i_from_arr = abs(arr[i]);
            int maybe_3;
            while (i_from_arr) {
                maybe_3 = i_from_arr % 10;
                i_from_arr /= 10;
            }
            if (maybe_3 == 3) {
                flag = true;
            }
        }
    }
    // Упорядочивание массива по возрастанию
    if (flag) {
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (arr[i] > arr[j]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
        // Вывод полученного массива
        for (int i = 0; i < N; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl << std::endl;
    }
    else std::cout << "В массиве не найдены числа, начинающиеся с тройки => сортировка невозможна!" << std::endl << std::endl;

    //--------------------------------------------------------------

    // Задание №2
    const int N_mat = 3, M_mat = 4;
    int mat[N_mat][M_mat];
    // Заполнение матрицы
    for (int i = 0; i < N_mat; ++i) {
        for (int j = 0; j < M_mat; ++j) {
            std::cin >> mat[i][j];
        }
    }
    // Поиск строки с максимальным значением суммы элементов
    int max_sum = std::numeric_limits<int>::min();
    int num_line = 0;
    for (int i = 0; i < N_mat; ++i) {
        int sum_of_lines = 0;
        for (int j = 0; j < M_mat; ++j) {
            sum_of_lines += mat[i][j];
        }
        if (max_sum < sum_of_lines) {
            max_sum = sum_of_lines;
            num_line = i;
        }
    }
    // Замена в найденной строке всех элементов на 999
    for (int j = 0; j < M_mat; ++j) {
        mat[num_line][j] = 999;
    }
    // Вывод полученной матрицы
    for (int i = 0; i < N_mat; ++i) {
        for (int j = 0; j < M_mat; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}