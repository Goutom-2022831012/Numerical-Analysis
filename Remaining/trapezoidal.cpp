#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x; 
}

int main() {
    double a, b;
    int n;

     cin >> a;
    cin >> b;
    cin >> n;

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for(int i = 1; i < n; i++) {
        sum += 2 * f(a + i*h);
    }

    double integral = (h/2.0) * sum;
    cout << fixed << setprecision(6);
    cout << "Approximate integral = " << integral << endl;

    return 0;
}
