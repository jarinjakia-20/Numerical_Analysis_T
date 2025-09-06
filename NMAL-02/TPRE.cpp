#include<iostream>
#include<cmath>
#define ll long long
#define endl '\n'
using namespace std;

double f(double x) 
{
    return 4*x*x + 3*x - 3;
}

double getRoot(double a,double b) 
{
    double root1=(-3+sqrt(57.0))/8.0;
    double root2=(-3-sqrt(57.0))/8.0;

    if(root1>=min(a,b) && root1<=max(a,b)) 
        return root1;
    else if(root2>=min(a,b) && root2<=max(a,b)) 
        return root2;
    else 
        return NAN;
}

void bisection(double a,double b,double t,double trueRoot) 
{
    if(f(a)*f(b)>0) 
    {
        cout<<"Error: f(a) and f(b) must have opposite signs"<<endl;
        return;
    }

    double error=abs(a-b);
    double c;

    while(error>=t) 
    {
        c=(a+b)/2;

        double tpre=fabs((trueRoot-c)/trueRoot)*100;
        cout<<"c = "<<c<<" ,TPRE = "<<tpre<<"%"<<endl;

        if(f(c)==0.0) 
            return;
        else if(f(a)*f(c)<0) 
            b=c;
        else 
            a=c;

        error=fabs(a-b);
    }
}

void regularFalsi(double a,double b,double t,double trueRoot) 
{
    if(f(a)*f(b)>0) 
    {
        cout<<"Error: f(a) and f(b) must have opposite signs"<<endl;
        return;
    }
    
    double error=abs(a-b);
    double c;
    
    while(error>=t) 
    {
        c=(a*f(b)-b*f(a))/(f(b)-f(a));

        double tpre=fabs((trueRoot-c)/trueRoot)*100;
        cout<<"c = "<<c<<" ,TPRE = "<<tpre<<"%"<<endl;

        if(f(c)==0.0) 
            return;
        else if(f(a)*f(c)<0) 
            b=c;
        else 
            a=c;

        error=fabs(a-b);
    }
}

int main() 
{
    double a,b;
    cin>>a>>b;
    double tolerance=1e-4;

    double trueRoot=getRoot(a,b);
    if(isnan(trueRoot)) 
    {
        cout<<"No known root lies within the interval"<<endl;
        return 1;
    }

    cout<<"Bisection Method :"<<endl;
    bisection(a,b,tolerance,trueRoot);

    cout<<"Regular Falsi Method :"<<endl;
    regularFalsi(a,b,tolerance,trueRoot);

}

