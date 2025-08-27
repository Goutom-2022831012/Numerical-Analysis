🧮 Gaussian Elimination (GE) is a method to solve systems of linear equations by reducing the coefficient matrix to an upper triangular form, then applying back substitution. However, plain GE can suffer from numerical instability if a pivot element is very small or zero, leading to large rounding errors. Partial Pivoting Gaussian Elimination (PPGE) improves accuracy by swapping the current row with the row below that has the largest pivot element in the same column before elimination. This reduces error propagation and ensures more stable results.(Example is given in GE_VS_PPGE.cpp) 
With Gaussian Elimination 
x1 = inf
x2 = -2.142857
x3 = 2.428571
Gaussian Elimination with Partial Pivoting
x1 = 2.794903
x2 = 1.476942
x3 = 0.046116
Real Answers (Upto 6 floating point )
x1 = 2.794903
x2 = 1.476942
x3 = 0.046116