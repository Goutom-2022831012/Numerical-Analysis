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

    cout << fixed << setprecision(6);
    double x = x0, y = y0;
    while (x < xn) {
        y = y + h * f(x, y);
        x = x + h;
        cout << x << "\t" << y << endl;
    }

    cout << "\nApproximate solution at x = " << xn << " is y = " << y << endl;

    return 0;
}
