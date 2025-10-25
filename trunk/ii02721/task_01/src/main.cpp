#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
int main() {
    double temp_now;
    double temp_prev;
    double temp_next;
    double heat_now;
    double heat_prev;
    double A, B, C, D;
    int steps;

    cout << "Введите начальную температуру (y) и подачу тепла (u): ";
    cin >> temp_now >> heat_now;

    cout << "Введите коэффициенты A, B, C, D: ";
    cin >> A >> B >> C >> D;

    cout << "Введите количество шагов моделирования: ";
    cin >> steps;

    temp_prev = temp_now;

    cout << "\nЛинейная модель\n";
    for (int k = 1; k <= steps; ++k) {
        temp_now = A * temp_prev + B * heat_now;
        cout << "Шаг " << k << ": температура = " << temp_now << " °C\n";
        temp_prev = temp_now;
    }

    cout << "\nНелинейная модель\n";
    temp_now = temp_prev;
    temp_prev = temp_now;
    heat_prev = heat_now;

    for (int k = 1; k <= steps; ++k) {
        temp_next = A * temp_now - B * std::pow(temp_prev, 2) + C * heat_now + D * std::sin(heat_prev);
        temp_prev = temp_now;
        temp_now = temp_next;
        heat_prev = heat_now;
        cout << "Шаг " << k << ": температура = " << temp_now << " C\n";
        
        if (k != steps) {
            cout << "Введите новое значение подачи тепла (u): ";
            cin >> heat_now;
        }
    }

    cout << "\nМоделирование завершено.\n";
    cout << "Итоговая температура: " << temp_now << " C\n";

    return 0;
}
