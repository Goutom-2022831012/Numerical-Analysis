#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n + 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        int maxRow = i;
        for(int j = i + 1; j < n; j++) {  
            if(fabs(a[j][i]) > fabs(a[maxRow][i])) {
                maxRow = j;
            }
        }
        swap(a[i], a[maxRow]);
        double pivot = a[i][i];
        if(fabs(pivot) < 1e-9) {
            cout << "No unique solution exists.\n";
            return 0;
        }

        for(int k = 0; k <= n; k++) {    
            a[i][k] /= pivot;
        }

        for(int j = 0; j < n; j++) {  
            if(j != i) {
                double factor = a[j][i];
                for(int k = 0; k <= n; k++) { 
                    a[j][k] -= factor * a[i][k];
                }
            }
        }
    }

    cout << "\nSolution:\n";
    for(int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << fixed << setprecision(6) << a[i][n] << endl;
    }

    return 0;
}
