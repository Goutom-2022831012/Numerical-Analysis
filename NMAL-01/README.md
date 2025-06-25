## 🧮 Bisection Method Comparison

The Bisection Method is a fundamental numerical technique used to find the real root of a continuous function by repeatedly narrowing down an interval where the function changes sign. It relies on the principle that if a function `f(x)` is continuous on `[a, b]` and `f(a) * f(b) < 0`, then at least one root lies within that interval. At each step, the method computes the midpoint `c = (a + b) / 2`, and based on the sign of `f(c)`, it replaces either `a` or `b` to maintain the sign change. This process continues until the interval is smaller than a desired tolerance.

Instead of guessing manually, a better approach is to automatically scan a wider range (such as `[-100, 100]`) in small steps and detect where the function changes sign (i.e., `f(x) * f(x + step) < 0`). This ensures the method starts with a valid root-containing interval.

The attached file **`Bisection.cpp`** implements both the traditional fixed-interval method and the better auto-scanning approach, compares their performance, and prints the time taken by each.
