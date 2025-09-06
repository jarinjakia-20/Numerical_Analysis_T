#include <iostream>
#include <cmath>
using namespace std;

double f(double x) 
{
    return log(3 * x) - 3;  
}

int main() 
{
    double a = 1, b = 10, c;
    double tol = 1e-4;
    int maxIter = 1000, iter = 0;

    if (f(a) * f(b) >= 0) 
    {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs." << endl;
        return 0;
    }

    cout << "Iter\t a\t\t b\t\t c\t\t f(c)" << endl;
    do 
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));  
        cout << iter << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iter++;
        if (iter > maxIter) 
        {
            cout << "Method did not converge." << endl;
            return 0;
        }

    } while (fabs(f(c)) > tol);

    cout << "\nRoot found: " << c << " after " << iter << " iterations." << endl;
    return 0;
}
