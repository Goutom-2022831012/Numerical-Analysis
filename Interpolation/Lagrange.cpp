#include <bits/stdc++.h>
using namespace std;

// Function to calculate Lagrange interpolation at a given point
double lagrangeInterpolation(vector<double> x, vector<double> y, double value) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    double value;
    cout << "Enter value to interpolate: ";
    cin >> value;

    double result = lagrangeInterpolation(x, y, value);
    cout << "Interpolated value at x = " << value << " is " << result << "\n";

    return 0;
}
