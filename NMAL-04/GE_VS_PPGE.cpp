#include <bits/stdc++.h>
using namespace std;

//Plain Gaussian Elimination (No pivoting)
vector<double> GE(vector<vector<double>> &a) {
    int n = a.size();
    for (int i = 0; i< n; i++) {
        for (int j = i + 1; j< n; j++) {
            if (fabs(a[i][i]) < 1e-12) continue; // Skiping 0 Divisor (If happans)
            double factor = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++)
            a[j][k] -= factor *a[i][k];
        }
    }
    vector<double> xs(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        xs[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            xs[i] -=  a[i][j] * xs[j];
            xs[i] /=  a[i][i];
    }
    return xs;
}

// Gaussian Elimination with partial pivoting
vector<double> PPGE(vector<vector<double>> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        // Find pivot row
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(a[j][i]) > fabs(a[pivot][i]))
           pivot = j;
        if ( pivot != i) {
            swap(a[i], a[pivot]);
        }
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[i][i]) < 1e-12) continue; // Skiping 0 Divisor (If happans)
            double factor = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++)
            a[j][k] -= factor * a[i][k];
        }
    }
  vector<double> xs(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        xs[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            xs[i] -= a[i][j] * xs[j];
            xs[i] /= a[i][i];
    }
    return xs;
}

int main() {
    cout << fixed << setprecision(6);
    int n = 3;
    vector<vector<double>> matrix = {
        {0, 2, 1, 3},
        {.033, -2, -3, -3},
        {3, -1, 2, 7}
    };
    vector<vector<double>> matrixGE = matrix;
    vector<vector<double>> matrixPPGE = matrix;

    cout << "With Gaussian Elimination "<< endl;
    vector<double> solGE = GE(matrixGE);
    for (int i = 0; i < n; i++)
     cout << "x" << i+1 << " = " << solGE[i] << endl;

    cout << "Gaussian Elimination with Partial Pivoting"<<endl;
    vector<double> solPPGE = PPGE(matrixPPGE);
    for (int i = 0; i < n; i++)
     cout << "x" << i+1 << " = " << solPPGE[i] << endl;

    return 0;
}
