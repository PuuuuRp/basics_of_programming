#include <iostream>
#include <bitset>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int A, i;
    cout << "Введите значения для А и i: ";
    cin >> A >> i;
    if (i < 0 || i > 7) { // проверка на правильность введения значения i-го бита
        cout << "Неправильное значение i!" << endl;
        return 0;
    }
    else if (A > 255) { // проверка на правильность введения значения числа А (1 байт)
        cout << "Неправильное значение A!" << endl;
        return 0;
    }
    bitset<8> BinA = A;
    //cout << A << " - " << BinA.to_string() << endl; // отладочный вывод для изначального A
    if (BinA[i] == 0) {
        A *= A;
        bitset<16> BinA = A;
        cout << A << " - " << BinA.to_string() << endl;
        i = 0;
        cout << "i = " << i << "; значение бита на нулевом индексе: " << BinA[i] << endl;
    }
    else {
        bitset<8> Bin125 = 125;
        string Repl = Bin125.to_string();
        cout << "125 - " << Repl << " (125, у которого НЕ заменены все чётные биты на 0)" << endl;
        Repl[1] = '0';
        Repl[3] = '0';
        Repl[5] = '0';
        Repl[7] = '0';
        cout << "125 - " << Repl << " (125, у которого заменены все чётные биты на 0)" << endl;
    }
    


    int BusNumber;
    cin >> BusNumber;
    switch (BusNumber) {
    case 113: 
        cout << "Калининград - Чапаево" << endl; 
        break;
    case 114:
        cout << "Калининград - Зеленоградск" << endl;
        break;
    case 117:
        cout << "Калининград - Мамоново" << endl;
        break;
    case 118:
        cout << "Калининград - Светлогорск" << endl;
        break;
    case 119:
        cout << "Калининград - Пионерский" << endl;
        break;
    case 125:
        cout << "Калининград - Донское" << endl;
        break;
    case 136:
        cout << "Калининград - Партизанское" << endl;
        break;
    case 141:
        cout << "Калининград - Зеленоградск" << endl;
        break;
    case 148:
        cout << "Калининград - Багратионовск" << endl;
        break;
    case 161:
        cout << "Калининград - Светлое" << endl;
        break;
    case 191:
        cout << "Калининград - Багратионовск" << endl;
        break;
    case 593:
        cout << "Калининград - Морское" << endl;
        break;
    case 802:
        cout << "Калининград - Гданьск" << endl;
        break;
    default:
        cout << "Номер автобуса не найден!" << endl;
    }

    return 0;
}