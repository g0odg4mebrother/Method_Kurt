#include <iostream>
#include <cmath>
using namespace std;

// Функция, определяющая правую часть дифференциального уравнения
double f(double t, double y) {
    // Пример функции: y' = t * y
    return t * y;
}

// Метод Рунге — Кутты четвертого порядка
void rungeKutta4(double t0, double y0, double h, int N, double* t, double* y) 
{
    t[0] = t0;
    y[0] = y0;

    for (int i = 0; i < N; ++i) {
        double k1 = f(t[i], y[i]);
        double k2 = f(t[i] + h / 2, y[i] + h * k1 / 2);
        double k3 = f(t[i] + h / 2, y[i] + h * k2 / 2);
        double k4 = f(t[i] + h, y[i] + h * k3);

        y[i + 1] = y[i] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
        t[i + 1] = t[i] + h;
    }
}

int main() 
{
    double t0 = 0.0;      // начальное время
    double y0 = 1.0;      // начальное условие
    double T = 2.0;       // конечное время
    const int N = 100;          // количество шагов

    // Шаг интегрирования
    double h = (T - t0) / N;

    // Массивы для хранения значений t и y
    double t[N + 1];
    double y[N + 1];

    // Решение методом Рунге — Кутты
    rungeKutta4(t0, y0, h, N, t, y);

    for (int i = 0; i <= N; ++i) {
        cout << "t[" << i << "] = " << t[i] << ", y[" << i << "] = " << y[i] << endl;
    }

    return 0;
}
