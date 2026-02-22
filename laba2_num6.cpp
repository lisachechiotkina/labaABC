#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    float a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    unsigned int* pa = (unsigned int*)&a;
    unsigned int* pb = (unsigned int*)&b;

    unsigned int bits_a = *pa;
    unsigned int bits_b = *pb;

    int sign_a = (bits_a >> 31) & 1;
    int sign_b = (bits_b >> 31) & 1;

    int exp_a = (bits_a >> 23) & 0xFF;
    int exp_b = (bits_b >> 23) & 0xFF;

    int mant_a = bits_a & 0x7FFFFF;
    int mant_b = bits_b & 0x7FFFFF;


    cout << "\nЧисло A: " << a << endl;
    cout << "Знак: " << sign_a << ", Порядок: " << exp_a << ", Мантисса: " << mant_a << endl;

    cout << "\nЧисло B: " << b << endl;
    cout << "Знак: " << sign_b << ", Порядок: " << exp_b << ", Мантисса: " << mant_b << endl;

    sign_b = !sign_b;

    cout << "\nВычитание " << a << " - " << b << " = " << a - b << endl;
    cout << "Операция выполнена в формате IEEE 754" << endl;

    return 0;
}