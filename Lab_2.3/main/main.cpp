#include <country.hpp>

int main() {
	SetConsoleOutputCP(CP_UTF8); 
	SetConsoleCP(CP_UTF8);
	setlocale(LC_ALL, "ru_RU.UTF-8");
	srand(time(0));
	
	Budget b(50000, 1.5);
	Country lol("Lol", "Kek", 500, 10000, {"Kek", "Kiev", "Kharkov", "Penek"}, b);
	lol.print_info();

	std::cout << "\n" << "==============================================================" << "\n\n";

	lol.pop_growth();
	lol.print_info();

	std::cout << "\n" << "==============================================================" << "\n\n";

	lol.set_capital("Popka");
	lol.print_info();

	std::cout << "\n" << "==============================================================" << "\n\n";

	return 0;
}
