#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <clocale>

class Country {
private:
    std::string title_;
    std::string capital_;
    float area_;
    std::vector<std::string> cities_;
public:
    Country() = default;
    Country(std::string title, std::string capital, float area, std::vector<std::string> cities);

    // Конструктор копирования
    Country(const Country& country);

    // Деструктор
    ~Country();

    // Переопределение оператора присваивания-копирования
    Country& operator=(const Country& country);

    // Переопределение оператора суммирования
    Country& operator+(const Country& country);

    // Переопределение оператора "плюс-равно"
    Country& operator+=(const Country& country);

    // Переопределение оператора умножения
    Country& operator*(const Country& country);

    // Геттеры
    std::string get_title() const;
    std::string get_capital() const;
    float get_area() const;

    // Сеттер на столицу
    void set_capital(std::string capital);

    // Вывод всей информации
    void print_info() const;

    // Присоединение новой территории
    void annexation(float new_area);
};

#endif // COUNTRY_H