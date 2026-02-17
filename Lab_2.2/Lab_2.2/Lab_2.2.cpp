#include "Country.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); // или 65001
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "=== Тест оператора + ===" << std::endl;
    Country russia("Lol", "Lola", 140, { "kiev", "new-york" });
    Country kek("Kek", "Kekker", 321, { "kiev", "kharkov" });
    russia + kek;
    russia.print_info();

    std::cout << "===========================================================" << std::endl;

    std::cout << "=== Тест оператора += ===" << std::endl;
    Country rus("Lol", "Lola", 140, { "kiev", "new-york" });
    Country keke("Kek", "Kekker", 321, { "kiev", "kharkov" });
    rus += keke;
    rus.print_info();

    std::cout << "===========================================================" << std::endl;

    std::cout << "=== Тест оператора * ===" << std::endl;
    Country russ("Lol", "Lola", 140, { "kiev", "new-york" });
    Country kekee("Kek", "Kekker", 321, { "kiev", "kharkov" });
    russ* kekee;
    russ.print_info();

    return 0;
}