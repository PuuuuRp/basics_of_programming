#include <iostream>
#include <cstdlib>

class Country {
public:
    Country() = default;
    Country(std::string title, std::string capital, std::string date_of_foundation, float area, int population) :
        title_(title), capital_(capital), date_of_foundation_(date_of_foundation), area_(area), population_(population) {
    }
    // Конструктор копирования
    Country(const Country& country) {
        title_ = country.title_;
        capital_ = country.capital_;
        date_of_foundation_ = country.date_of_foundation_;
        area_ = country.area_;
        population_ = country.population_;
    }
    ~Country() {
        std::cout << "Деструктор запущен" << std::endl;
    }

    // Геттеры
    std::string get_title() { return title_; }
    std::string get_capital() { return capital_; }
    std::string get_date_of_foundation() { return date_of_foundation_; }
    float get_area() { return area_; }
    int get_population() { return population_; }

    // Сеттер на столицу
    void set_capital(std::string capital) {
        capital_ = capital;
    }

    // Вывод всей информацию
    void print_info() {
        std::cout << "Название: " << title_ << std::endl;
        std::cout << "Столица: " << capital_ << std::endl;
        std::cout << "Дата основания: " << date_of_foundation_ << std::endl;
        std::cout << "Площадь: " << area_ << " млн. км2" << std::endl;
        std::cout << "Население: " << population_ << std::endl;
    }

    // Присоединение новой территории
    void annexation(float new_area) {
        area_ += new_area;
    }

    // Рост населения
    void pop_growth() {
        population_ += rand() % 1000;
    }

private:
    std::string title_;
    std::string date_of_foundation_;
    float area_;
    int population_;

protected:
    std::string capital_;
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    Country russia("Россия", "", "1991 год", 17.0, 143551838);
    std::string cap;
    std::cin >> cap;
    russia.set_capital(cap);
    std::cout << "==============================" << std::endl;
    russia.print_info();
    std::cout << "==============================" << std::endl;
    russia.annexation(0.125);
    russia.pop_growth();
    russia.print_info();
    std::cout << "==============================" << std::endl;
    Country cussia(russia);
    cussia.set_capital("Санкт-Петербург");
    cussia.print_info();
    std::cout << "==============================" << std::endl;

    return 0;
}