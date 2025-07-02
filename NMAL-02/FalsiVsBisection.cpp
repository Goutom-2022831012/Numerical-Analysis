#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return 4 * x * x + 3 * x - 3;
}
const double true_root =(-3 + sqrt(57)) / 8.0;
void bisection(double a, double b, double tol = 1e-4) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid.\n";
        return;
    }
    cout << "\nBisection Method:\n";
    cout << fixed << setprecision(6);
    cout << "Iteration\ta\t\tb\t\tc\t\tTPRE (%)\n";
    int i = 0;
    double c = (a + b) / 2.0;
    double prev_c = c;
    double error = 100;
    while (error > tol) {
        double tpre = fabs((true_root - c) / true_root) * 100;
        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << tpre << endl;
        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        prev_c = c;
        c = (a + b) / 2.0;
        error = fabs((c - prev_c) / c);
        i++;
    }
    cout << "Root: " << c << endl;
}

void falsePosition(double a, double b, double tol = 1e-4) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid.\n";
        return;
    }
    cout << "\nFalse Position Method:\n";
    cout << fixed << setprecision(6);
    cout << "Iteration\ta\t\tb\t\tc\t\tTPRE (%)\n";
    int i = 0;
    double c = (a * f(b) - b * f(a)) / (f(b) - f(a));
    double prev_c = c;
    double error = 100;
    while (error > tol) {
        double tpre = fabs((true_root - c) / true_root) * 100;
        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << tpre << endl;

        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        prev_c = c;
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        error = fabs((c - prev_c) / c);
        i++;
    }

    cout << "Root: " << c << endl;
}

int main() {
    double a = 0.0, b = 1.0;
    bisection(a, b);
    falsePosition(a, b);
    return 0;
}
/*
Bisection Method:
Iteration       a               b               c               TPRE (%)
0       0.000000        1.000000        0.500000        12.084713
1       0.500000        1.000000        0.750000        31.872930
2       0.500000        0.750000        0.625000        9.894109
3       0.500000        0.625000        0.562500        1.095302
4       0.562500        0.625000        0.593750        4.399403
5       0.562500        0.593750        0.578125        1.652051
6       0.562500        0.578125        0.570312        0.278374
7       0.562500        0.570312        0.566406        0.408464
8       0.566406        0.570312        0.568359        0.065045
9       0.568359        0.570312        0.569336        0.106665
10      0.568359        0.569336        0.568848        0.020810
11      0.568359        0.568848        0.568604        0.022118
12      0.568604        0.568848        0.568726        0.000654
13      0.568726        0.568848        0.568787        0.010078
Root: 0.568756

False Position Method:
Iteration       a               b               c               TPRE (%)
0       0.000000        1.000000        0.428571        24.644040
1       0.428571        1.000000        0.540984        4.878542
2       0.540984        1.000000        0.563506        0.918371
3       0.563506        1.000000        0.567756        0.171197
4       0.567756        1.000000        0.568548        0.031855
5       0.568548        1.000000        0.568696        0.005925
Root: 0.568723*/