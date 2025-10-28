#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return x + y; 
}

int main() {
    double x0, y0, xn, h;

    cin >> x0;
    cin >> y0;
    cin >> h;
    cin >> xn;

    double x = x0;
    double y = y0;

    cout << fixed << setprecision(6);

    while (x < xn) {
        double y_pred = y + h * f(x, y);
        double x_next = x + h;
        y = y + (h / 2.0) * (f(x, y) + f(x_next, y_pred));
        x = x_next;
        cout << x << "\t" << y << endl;
    }
    cout << "\nApprox value of y at x = " << xn << " is " << y << endl;

    return 0;
}
