#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

double df(double x) {
    return 3*x*x - 1;
}

int main() {
    double x0, x1, tol;
    int maxIter;

    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    int iter = 0;
    cout << fixed << setprecision(6);

    while (iter < maxIter) {
        if (df(x0) == 0) { 
            cout << "Derivative zero. Method fails.\n";
            return 1;
        }

        x1 = x0 - f(x0) / df(x0); 
        cout << "Iteration " << iter+1 << ": x = " << x1 << "\n";

        if (fabs(x1 - x0) < tol) {
            cout << "\nRoot found: " << x1 << "\n";
            return 0;
        }

        x0 = x1;
        iter++;
    }
    cout << "Method did not converge within max iterations.\n";
    return 0;
}
