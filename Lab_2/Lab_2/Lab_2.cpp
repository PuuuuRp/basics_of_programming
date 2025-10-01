#include <iostream>
#include <bitset>
#include <cstddef>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    //unsigned short A;
    //int i;
    //cout << "Введите значения для А и i: ";
    //cin >> A >> i;
    //if (i < 0 || i > 15) { // проверка на правильность введения значения i-го бита
    //    cout << "Неправильное значение i!" << endl;
    //    return 0;
    //}
    //bitset<16> BinA = A;
    ////cout << A << " - " << BinA << endl; // отладочный вывод для изначального A

    //bitset<16> Sup(1 << i);
    //if ((BinA & Sup) == 0) {
    //    A *= A;
    //    bitset<16> BinA = A;
    //    cout << A << " - " << BinA << endl;

    //    bitset<16> x(~(1 << i));
    //    BinA = BinA & x;
    //    A = BinA.to_ulong();
    //    cout << A << " i0 - " << BinA << endl;
    //}
    //else {
    //    int mask = 0b1010'1010'1010'1010;
    //    bitset<16> Bin125 = 125;
    //    cout << "125 - " << Bin125 << endl;
    //    bitset<16> m = mask;
    //    Bin125 = Bin125 & m;
    //    int intBin125 = Bin125.to_ulong();
    //    cout << intBin125 << " - " << Bin125 << endl;
    //}
    
    ///////////////////////////////////////
    int BusNumber;
    cin >> BusNumber;
    cout << BusNumber << endl;
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