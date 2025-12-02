#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double piecewise_function(double x, double a, double b) {
    if (x <= a) {
        return sin(x) - 1.0;
    } else if (x < b) {
        return cos(x) + 2.0;
    } else {
        // Проверка на область определения тангенса
        double remainder = fmod(x - M_PI/2, M_PI);
        if (fabs(remainder) < 1e-10) {
            return NAN;  // Не определено
        }
        return tan(x) - 0.5;
    }
}

int main() {
    double a = 0.0;
    double b = M_PI / 2.0;
    double test_values[] = {-1.0, 0.0, 1.0, M_PI/4, M_PI/2, 2.0};
    
    cout << "C++ реализация:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "x\t\tf(x)" << endl;
    cout << "------------------------" << endl;
    
    for (double x : test_values) {
        double result = piecewise_function(x, a, b);
        cout << fixed << setprecision(4);
        cout << x << "\t\t";
        if (isnan(result)) {
            cout << "undefined" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}
