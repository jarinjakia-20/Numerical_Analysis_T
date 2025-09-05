#include <iostream>
#include <cmath>
using namespace std;

double TOLERANCE = 0.0001;

double f(double x) 
{
    return 4*x*x + 3*x - 3;
}

void bisectionTraditional(double a, double b) 
{
    if (f(a) * f(b) >= 0) 
    {
        cout << "Invalid interval for traditional Bisection.\n";
        return;
    }

    double c;
    int iteration = 0;
    double error = abs(b - a);

    cout << "Traditional Bisection Method:\n";
    while (error >= TOLERANCE) 
    {
        iteration++;
        c = (a + b) / 2;
        cout << "Iteration " << iteration << ": a=" << a << ", b=" << b << ", c=" << c << ", f(c)=" << f(c) << ", error=" << error << endl;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        error = abs(b - a);
    }

    cout << "Approximate root (Traditional) = " << c << " in " << iteration << " iterations.\n\n";
}

bool betterRange(double &a, double &b) 
{
    double step = 0.1;
    for (double x = -100; x < 100; x += step) 
    {
        if (f(x) * f(x + step) < 0) 
        {
            a = x;
            b = x + step;
            return true;
        }
    }
    return false;
}

void bisectionBetter(double a, double b) 
{
    if (!betterRange(a, b)) 
    {
        cout << "No sign change found in range [-100, 100].\n";
        return;
    }

    int iteration = 0;
    double c;

    cout << "Improved Bisection Method (Better Range):\n";
    while (abs(b - a) >= TOLERANCE) 
    {
        iteration++;
        c = (a + b) / 2;

        if (f(c) == 0.0)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Approximate root (Better Range) = " << c << " in " << iteration << " iterations.\n";
}

int main() 
{
    double a, b;
    cout << "Enter initial interval a and b for traditional Bisection: ";
    cin >> a >> b;

    bisectionTraditional(a, b);

    bisectionBetter(a, b);

    return 0;
}
