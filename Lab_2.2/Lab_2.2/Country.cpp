#include "Country.h"

Country::Country() = default;

// Конструктор с параметрами
Country::Country(std::string title, std::string capital, float area, std::vector<std::string> cities) :
    title_(title), capital_(capital), area_(area), cities_(cities) {
}

// Конструктор копирования
Country::Country(const Country& country) {
    title_ = country.title_;
    capital_ = country.capital_;
    area_ = country.area_;
    cities_.resize(country.cities_.size());
    std::copy(country.cities_.begin(), country.cities_.end(), cities_.begin());
}

// Деструктор
Country::~Country() {
    cities_.clear();
    std::cout << "Деструктор выполнился" << std::endl;
}

// Переопределение оператора присваивания-копирования

Country& Country::operator=(const Country& country) {
    title_ = country.title_;
    capital_ = country.capital_;
    area_ = country.area_;
    cities_ = country.cities_;
    return *this;
}

// Переопределение оператора суммирования
Country Country::operator+(const Country& other) const {
    Country result;
    result.title_ = title_ + "-" + other.title_;
    result.capital_ = (area_ < other.area_) ? other.capital_ : capital_;
    result.area_ = area_ + other.area_;

    result.cities_ = cities_;
    result.cities_.reserve(result.cities_.size() + other.cities_.size());
    for (const auto& city : other.cities_) {
        if (std::find(result.cities_.begin(), result.cities_.end(), city)
            == result.cities_.end()) {
            result.cities_.push_back(city);
        }
        else {
            result.cities_.push_back(city + " новый");
        }
    }

    return result;
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
Country Country::operator*(const Country& other) const {
    Country result;
    result.title_ = "путь " + title_ + " -> " + other.title_;
    result.area_ = min(other.area_, area_);

    result.cities_.resize(2);
    result.cities_[0] = capital_;
    result.cities_[1] = other.capital_;
  
    if (cities_.size() > 2) {
        int ind = rand() % (cities_.size() - 1) + 1;
        result.cities_.reserve(result.cities_.size() + 1);
        if (std::find(result.cities_.begin(), result.cities_.end(), cities_[ind]) != result.cities_.end()) {
            result.cities_.push_back(cities_[ind] + " новый");
        }
        else result.cities_.push_back(cities_[ind]);
    }

    if (other.cities_.size() > 2) {
        int ind = rand() % (other.cities_.size() - 1) + 1;
        result.cities_.reserve(result.cities_.size() + 1);
        if (std::find(result.cities_.begin(), result.cities_.end(), other.cities_[ind]) != result.cities_.end()) {
            result.cities_.push_back(other.cities_[ind] + " новый");
        }
        else result.cities_.push_back(other.cities_[ind]);
    }

    result.capital_ = "нет";

    return result;
}

// Геттеры
std::string Country::get_title() const { return title_; }
std::string Country::get_capital() const { return capital_; }
float Country::get_area() const { return area_; }

// Сеттер на столицу
void Country::set_capital(std::string capital) {
    capital_ = capital;

    if (std::find(cities_.begin(), cities_.end(), capital) == cities_.end()) {
        cities_.reserve(cities_.size() + 1);
        cities_.push_back(capital);
    }
    std::reverse(cities_.begin(), cities_.end());
}
void Country::set_title(std::string title) {
    title_ = title;
}
void Country::set_area(float area) {
    area_ = area;
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