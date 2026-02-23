#include "Country.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); // или 65001
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(0));

    std::cout << "==========================================================" << std::endl;
    Country Lol("Lol", "Lola", 140, {"Lola", "kiev", "new-york" });
    Country kek("Kek", "Kekker", 321, {"Kekker", "kiev", "kharkov" });
    Country smth;
    smth = Lol + kek;
    smth.print_info();

    std::cout << smth.get_title();

    std::cout << "===========================================================" << std::endl;

    Country Lolo("Lol", "Lola", 140, { "Lola", "kiev", "new-york" });
    Country keke("Kek", "Kekker", 321, { "Kekker", "kiev", "kharkov" });
    Lolo += keke;
    Lolo.print_info();

    std::cout << "===========================================================" << std::endl;

    Country Loloo("Lol", "Lola", 140, { "Lola", "kiev", "new-york", "moskow", "ekb"});
    Country kekee("Kek", "Kekker", 321, { "Kekker", "kiev", "kharkov", "irkutsk", "vladik"});
    Country s;
    s = Loloo * kekee;
    s.print_info();

    return 0;
}