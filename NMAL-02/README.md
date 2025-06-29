🧮 The False Position Method is a numerical way to find roots of equations like f(x) = 0. It uses a line between two points (a, f(a)) and (b, f(b)) to estimate the root c by:

  c = (a * f(b) - b * f(a)) / (f(b) - f(a))

This method needs f(a) and f(b) to have opposite signs, meaning the root lies between a and b.

False Position uses the slope between points, so it often converges faster.

Bisection simply halves the interval, so it always converges but usually more slowly.


(a) Iterations of False Position Method
For f(x) = ln(3x) - 3
Provided in the Falsi.cpp file .

(b) Comparison between False Position and Bisection Methods
For f(x) = 4x² + 3x - 3
Provided in the FalsiVsBisection.cpp file.
Summary: False Position converged much faster here.

(c) Pitfall of False Position on f(x) = x^10 - 1

Root is at x = 1, but the function is very flat near the root.
False Position gets stuck near 0.5 because the slope there is almost zero, causing slow convergence (endpoint freezing).
Bisection avoids this by always halving the interval, so it converges reliably.