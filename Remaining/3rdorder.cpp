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

    double x = x0, y = y0;

    cout << fixed << setprecision(6);
    while (x < xn) {
        double k1 = f(x, y);
        double k2 = f(x + h/2.0, y + h/2.0*k1);
        double k3 = f(x + h, y - h*k1 + 2*h*k2);

        y = y + (h/6.0)*(k1 + 4*k2 + k3);
        x = x + h;

        cout << x << "\t" << y << endl;
    }

    cout << "\nApprox solution at x = " << xn << " is y = " << y << endl;

    return 0;
}
