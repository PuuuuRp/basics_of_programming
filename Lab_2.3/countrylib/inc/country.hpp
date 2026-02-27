#pragma once
#define COUNTRY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <clocale>

struct City {
    std::string name = "";
    int population = 0;
    float available_money = 0;
};

class Budget {
private:
    int money_sup_ = 0;
    float priority_for_capital_ = 0.0;
public:
    Budget();

    Budget(int money_sup, float priority_for_capital);

    Budget(const Budget& other);

    ~Budget();

    Budget& operator=(const Budget& other);

    int get_money_sup();
    float get_priority_for_capital();

    void set_money_sup(int m);
    void set_priority_for_capital(float p);

    void changing_money(int x);
};

class Country {
private:
    Budget budget_;
    std::string title_ = "";
    std::string capital_ = "";
    std::string date_of_foundation_ = "";
    float area_ = 0;
    std::vector<City> cities_{};
    int population_ = 0;
public:
    Country();
    Country(std::string title, std::string capital, float area, int population, std::vector<std::string> name_c, Budget budget);

    // Конструктор копирования
    Country(const Country& country);

    // Деструктор
    ~Country();

    // Переопределение оператора присваивания-копирования
    Country& operator=(const Country& country);

    // Переопределение оператора суммирования
    Country operator+(const Country& other) const;

    // Переопределение оператора "плюс-равно"
    Country& operator+=(const Country& country);

    // Переопределение оператора умножения
    Country operator*(const Country& country) const;

    // Распределение бюджета по городам согласно населению
    void budget_allocation();

    // Геттеры
    std::string get_title() const;
    std::string get_capital() const;
    float get_area() const;

    // Сеттеры
    void set_capital(std::string capital);
    void set_title(std::string title);
    void set_area(float area);

    // Вывод всей информации
    void print_info() const;

    // Присоединение новой территории
    void annexation(float new_area);

    // Рост населения
    void pop_growth();
};