#include <country.hpp>

// Бюджет
Budget::Budget() = default;

Budget::Budget(int money_sup, float priority_for_capital): money_sup_(money_sup), priority_for_capital_(priority_for_capital){}

Budget::Budget(const Budget& other) {
    money_sup_ = other.money_sup_;
    priority_for_capital_ = other.priority_for_capital_;
}

Budget::~Budget(){}

Budget& Budget::operator=(const Budget& other) {
    money_sup_ = other.money_sup_;
    priority_for_capital_ = other.priority_for_capital_;
    return *this;
}

int Budget::get_money_sup() {
    return money_sup_;
}
float Budget::get_priority_for_capital() {
    return priority_for_capital_;
}

void Budget::set_money_sup(int m) {
    money_sup_ = m;
}
void Budget::set_priority_for_capital(float p) {
    priority_for_capital_ = p;
}

void Budget::changing_money(int x) {
    money_sup_ += x;
}

//========================================================================================================================
// Страна
Country::Country() = default;

// Конструктор с параметрами
Country::Country(std::string title, std::string capital, float area, int population, std::vector<std::string> name_c, Budget budget) :
    title_(title), capital_(capital), area_(area), population_(population) {
    budget_ = budget;

    cities_.resize(name_c.size());
    for (size_t i = 0; i < name_c.size(); ++i) {
        cities_[i].name = name_c[i];
    }

    int cur_population = population;
    for (size_t i = 0; i < cities_.size() - 1; ++i) {
        cities_[i].population = rand() % (cur_population + 1);
        cur_population -= cities_[i].population;
    }
    cities_[cities_.size() - 1].population = cur_population;

    budget_allocation();
}

// Конструктор копирования
Country::Country(const Country& country) {
    title_ = country.title_;
    capital_ = country.capital_;
    area_ = country.area_;
    cities_.resize(country.cities_.size());
    std::copy(country.cities_.begin(), country.cities_.end(), cities_.begin());
    budget_ = country.budget_;
}

// Деструктор
Country::~Country() {
    cities_.clear();
    //std::cout << "Деструктор выполнился" << std::endl;
}

// Переопределение оператора присваивания-копирования
Country& Country::operator=(const Country& country) {
    title_ = country.title_;
    capital_ = country.capital_;
    area_ = country.area_;
    cities_ = country.cities_;
    budget_ = country.budget_;
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
        bool flag = false;
        for (size_t j = 0; j < result.cities_.size(); ++j) {
            if (result.cities_[j].name == city.name) flag = true;
        }
        if (!flag) {
            result.cities_.push_back(city);
        }
        else {
            City c = city;
            c.name += " новый";
            result.cities_.push_back(c);
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
    for (const auto& city : country.cities_) {
        bool flag = false;
        for (size_t j = 0; j < cities_.size(); ++j) {
            if (cities_[j].name == city.name) flag = true;
        }
        if (!flag) {
            cities_.push_back(city);
        }
        else {
            City c = city;
            c.name += " новый";
            cities_.push_back(c);
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
    result.cities_[0] = cities_[0];
    result.cities_[1] = other.cities_[0];

    if (cities_.size() > 2) {
        int ind = rand() % (cities_.size() - 1) + 1;
        result.cities_.reserve(result.cities_.size() + 1);
        bool flag = false;
        for (size_t j = 0; j < result.cities_.size(); ++j) {
            if (result.cities_[j].name == cities_[ind].name) flag = true;
        }
        if (!flag) {
            result.cities_.push_back(cities_[ind]);
        }
        else {
            City c = cities_[ind];
            c.name += " новый";
            result.cities_.push_back(c);
        }
    }
    else if (cities_.size() == 2) result.cities_.push_back(cities_[1]);

    if (other.cities_.size() > 2) {
        int ind = rand() % (other.cities_.size() - 1) + 1;
        result.cities_.reserve(result.cities_.size() + 1);
        bool flag = false;
        for (size_t j = 0; j < result.cities_.size(); ++j) {
            if (result.cities_[j].name == other.cities_[ind].name) flag = true;
        }
        if (!flag) {
            result.cities_.push_back(other.cities_[ind]);
        }
        else {
            City c = other.cities_[ind];
            c.name += " новый";
            result.cities_.push_back(c);
        }
    }
    else if (other.cities_.size() == 2) result.cities_.push_back(other.cities_[1]);

    result.capital_ = "нет";

    return result;
}

// Распределение бюджета по городам согласно населению
void Country::budget_allocation() {
    float cur_budget = budget_.get_money_sup();
    cities_[0].available_money = cities_[0].population * cur_budget * budget_.get_priority_for_capital() / population_;
    cur_budget -= cities_[0].available_money;

    for (size_t i = 1; i < cities_.size(); ++i) {
        cities_[i].available_money = cities_[i].population * cur_budget / population_;
        cur_budget -= cities_[i].available_money;
    }
}

// Геттеры
std::string Country::get_title() const { return title_; }
std::string Country::get_capital() const { return capital_; }
float Country::get_area() const { return area_; }

// Сеттер на столицу
void Country::set_capital(std::string capital) {
    if (capital_ != capital) {
        capital_ = capital;

        bool flag = false;
        for (size_t i = 0; i < cities_.size(); ++i){
            if (cities_[i].name == capital) flag = true;
        }
        
        if (!flag) {
            cities_.reserve(cities_.size() + 1);
            City cap;
            cap.name = capital;
            cap.population = rand() % 5000 + 1;
            population_ += cap.population;
            cities_.push_back(cap);
            std::reverse(cities_.begin(), cities_.end());
        }
        else {
            for (size_t i = 0; i < cities_.size(); ++i) {
                if (cities_[i].name == capital) {
                    std::swap(cities_[0], cities_[i]);
                    break;
                }
            }

        }

        budget_allocation();

    }
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
    std::cout << "Население: " << population_ << " чел." << std::endl;
    std::cout << "Города: ";
    for (size_t i = 0; i < cities_.size(); ++i) {
        std::cout << cities_[i].name << "(" << cities_[i].population << ", " << cities_[i].available_money << ")";
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

// Рост населения
void Country::pop_growth() {
    int change = rand() % 2000 - 1000;
    population_ += change;
    int ind = rand() % cities_.size();
    cities_[ind].population += change;
    budget_allocation();
}