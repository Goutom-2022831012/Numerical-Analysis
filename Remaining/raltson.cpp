#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return x + y; 
}

int main() {
    double x0, y0, h, xn;

    cin >> x0;
    cin >> y0;
    cin >> h;
    cin >> xn;

    double x = x0;
    double y = y0;

    cout << fixed << setprecision(6);
    while (x < xn) {
        double k1 = f(x, y);
        double k2 = f(x + 3.0/4.0*h, y + 3.0/4.0*h*k1);

        y = y + h * (1.0/3.0*k1 + 2.0/3.0*k2);
        x = x + h;

        cout << x << "\t" << y << endl;
    }

    cout << "\nApproximate solution at x = " << xn << " is y = " << y << endl;

    return 0;
}
