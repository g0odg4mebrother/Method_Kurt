#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return sin(x); 
}
double Method_Kurt(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = 0.5 * (f(a) + f(b)); 

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

int main() {
    setlocale(LC_ALL, "rus");
    double a = 0.0;  
    double b = M_PI; 
    int n = 1000;  

    double integral = Method_Kurt(a, b, n);
    cout << "Приблизительное значение интеграла: " << integral << endl;

    return 0;
}