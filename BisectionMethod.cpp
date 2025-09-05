#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x)
{
    return 4*x*x + 3*x - 3;
}

void bisection(double a, double b, double tol = 1e-6, int max_iter = 100) 
{
    if (f(a) * f(b) >= 0) 
    {
        cout << "Error: f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c; 
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iter\t a\t\t b\t\t c\t\t f(c)\n";

    while ((b - a) >= tol) 
    {
        c = (a + b) / 2.0;
        double fc = f(c);
        cout << iteration + 1 << "\t" << a << "\t" << b << "\t" << c << "\t" << fc << endl;

        if (fabs(fc) < tol) 
        {
            break;
        }

        if (f(a) * fc < 0) 
        {
            b = c;
        } 
        else 
        {
            a = c;
        }

        iteration++;
    }

    c = (a + b) / 2.0;
    cout << "\nApproximate root: " << c << " after " << iteration << " iterations.\n";
    cout << "f(root) :" << f(c) << endl;
}

int main() 
{
    double a;
    double b;
    cout << "Enter the interval:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    bisection(a, b);

    return 0;
}
