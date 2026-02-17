#include "Country.h"

// Конструктор с параметрами
Country::Country(std::string title, std::string capital, float area, std::vector<std::string> cities) :
    title_(title), capital_(capital), area_(area), cities_(cities) {
}

// Конструктор копирования
Country::Country(const Country& country) {
    title_ = country.title_;
    capital_ = country.capital_;
    area_ = country.area_;
    cities_.reserve(country.cities_.size());
    std::copy(country.cities_.begin(), country.cities_.end(), cities_.begin());
}

// Деструктор
Country::~Country() {
    cities_.clear();
    std::cout << "Деструктор выполнился" << std::endl;
}

// Переопределение оператора присваивания-копирования
Country& Country::operator=(const Country& country) {
    if (this != &country) {
        title_ = country.title_;
        capital_ = country.capital_;
        area_ = country.area_;

        cities_.clear();
        for (size_t i = 0; i < country.cities_.size(); ++i) {
            cities_.reserve(cities_.size() + 1);
            cities_.push_back(country.cities_[i]);
        }
    }
    return *this;
}

// Переопределение оператора суммирования
Country& Country::operator+(const Country& country) {
    title_ += "-" + country.title_;
    if (area_ < country.area_) {
        capital_ = country.capital_;
    }
    area_ += country.area_;

    cities_.reserve(cities_.size() + country.cities_.size());
    for (size_t i = 0; i < country.cities_.size(); ++i) {
        if (std::find(cities_.begin(), cities_.end(), country.cities_[i]) != cities_.end()) {
            cities_.push_back(country.cities_[i] + " новый");
        }
        else {
            cities_.push_back(country.cities_[i]);
        }
    }
    return *this;
}

// Переопределение оператора "плюс-равно"
Country& Country::operator+=(const Country& country) {
    title_ += "-" + country.title_;
    if (area_ < country.area_) {
        capital_ = country.capital_;
    }
    area_ += country.area_;

    cities_.reserve(cities_.size() + country.cities_.size());
    for (size_t i = 0; i < country.cities_.size(); ++i) {
        if (std::find(cities_.begin(), cities_.end(), country.cities_[i]) != cities_.end()) {
            cities_.push_back(country.cities_[i] + " новый");
        }
        else {
            cities_.push_back(country.cities_[i]);
        }
    }
    return *this;
}

// Переопределение оператора умножения
Country& Country::operator*(const Country& country) {
    title_ = "путь " + title_ + " -> " + country.title_;
    area_ = min(country.area_, area_);

    cities_.resize(3);
    std::reverse(cities_.begin(), cities_.end());
    cities_[0] = capital_;
    cities_[1] = country.capital_;
    if (!cities_[2].empty()) {
        cities_.reserve(4);
        if (std::find(cities_.begin(), cities_.end(), country.cities_[0]) != cities_.end()) {
            cities_.push_back(country.cities_[0] + " новый");
        }
        else cities_.push_back(country.cities_[0]);
    }
    else cities_.push_back(country.cities_[0]);

    capital_ = "нет";
    return *this;
}

// Геттеры
std::string Country::get_title() const { return title_; }
std::string Country::get_capital() const { return capital_; }
float Country::get_area() const { return area_; }

// Сеттер на столицу
void Country::set_capital(std::string capital) {
    capital_ = capital;
}

// Вывод всей информации
void Country::print_info() const {
    std::cout << "Название: " << title_ << std::endl;
    std::cout << "Столица: " << capital_ << std::endl;
    std::cout << "Площадь: " << area_ << " млн. км2" << std::endl;
    std::cout << "Города: ";
    for (size_t i = 0; i < cities_.size(); ++i) {
        std::cout << cities_[i];
        if (i < cities_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Присоединение новой территории
void Country::annexation(float new_area) {
    area_ += new_area;
}