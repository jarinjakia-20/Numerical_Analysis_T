#include<iostream>
#include<cmath>
#define ll long long
#define endl '\n'
using namespace std;

double f(double x)
{
    return pow(x,5)-3*x+5;
}

double df(double x)
{
    return 5*pow(x,4)-3;
}

void newtonRaphson(double a,double t)
{
    double error = f(a)/df(a);

    while(abs(error)>=t)
    {
        error = f(a)/df(a);
        a = a-error;
    }
    cout<<"Root is "<<a<<endl;
}

int main() 
{
    double a;
    cin>>a;
    double tolerance = 1e-3;
    newtonRaphson(a,tolerance);
}


