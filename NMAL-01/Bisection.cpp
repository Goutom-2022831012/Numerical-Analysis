#include<bits/stdc++.h>
#include <ctime>
using namespace std;

double f(double x){
    return 4 * x * x + 3 * x - 3;
}
double bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) > 0)
        return NAN;
    double error = abs(a - b);
    while (error >= tolerance) {
        double c = (a + b) / 2.0;
    if (f(c) == 0.0)
            return c;
     else if (f(a) *f(c) > 0)
            a = c;
     else
            b = c;
        error = abs(a - b);
    }
    return (a + b) / 2.0;
}
void TraditionalApproach(double tolerance) {
    double a = -1, b = 10;
    clock_t start = clock();
    double root = bisection(a, b, tolerance);
    clock_t end = clock();

    if (!isnan(root))
    cout << "Root (Traditional Approach) : " << root << endl;
    else
    cout << "Traditional approach failed." << endl;
    cout << "Time taken by Traditional Approach: " << (double)(end - start) * 1e9 / CLOCKS_PER_SEC << " nenoseconds\n";
}
bool findInterval(double& a, double& b, double start = -100, double end = 100, double i = 0.1) {
    for (double x = start; x < end; x += i) {
        if (f(x) * f(x + i) < 0) {
            a = x;
            b = x + i;
            return true;
        }
    }
    return false;
}
void BetterApproach(double tolerance) {
    double a, b;
    clock_t sstart = clock();
    bool found = findInterval(a, b);
    clock_t send = clock();

 if (found) {
        clock_t bstart = clock();
        double root = bisection(a, b, tolerance);
        clock_t bend = clock();

        cout << "Root (Better Auto Approach) : " << root << endl;
        cout << "Interval Search Time: " << (double)(send - sstart) * 1e9 / CLOCKS_PER_SEC<< " nenoseconds\n";
        cout << "Bisection Time: " << (double)(bend - bstart) * 1e9 / CLOCKS_PER_SEC<< " nenoseconds\n";
    } else {
        cout << "No valid interval found using better approach." << endl;
    }
}
int main() {
    double tolerance = 1e-6;
    TraditionalApproach(tolerance);
    BetterApproach(tolerance);
    // both taking 1000 ns but in better approach we are finding valid range automaticly instead of assuming the range 
    return 0;
}
