#include <bits/stdc++.h>
using namespace std;

void printTable(vector<vector<double>> &table, vector<double> &x, int n) {
  cout << fixed << setprecision(6);
     cout << "\nDivided Difference Table:\n";
    cout << "x\t";
    for (int j = 0; j < n; j++) {
        cout << "f" << j << "\t";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << table[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}
double newtonInterpolation(vector<double> x, vector<double> y, double value) {
    int n = x.size();
    vector<vector<double>> divDiff(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++)
        divDiff[i][0] = y[i];
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            divDiff[i][j] = (divDiff[i+1][j-1] - divDiff[i][j-1]) / (x[i+j] - x[i]);
        }
    }
    printTable(divDiff, x, n);
    double result = divDiff[0][0];
    double term = 1.0;

    for (int j = 1; j < n; j++) {
        term *= (value - x[j-1]);
        result += divDiff[0][j] * term;
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

    double result = newtonInterpolation(x, y, value);
    cout << "\nInterpolated value at x = " << value << " is " << result << "\n";

    return 0;
}
