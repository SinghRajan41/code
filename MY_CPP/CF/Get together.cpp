#include<iostream>
#include<iomanip>
#define ll long long int
using namespace std;
bool good(double x[], double v[],int n,double time);
int main()
{
    int n;
    cin>>n;
    double x[n],v[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>v[i];
    double low,high;
    if(n==1)
    {
        cout<<"0\n";
        exit(0);
    }
    low = 0;
    high = 3e12;
    for(int i=0;i<200;i++)
    {
        double mid = (low + high) / 2;
        if(good(x,v,n,mid))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout<<setprecision(20)<<(low+high)/2<<"\n";
    return 0;
}
bool good(double x[], double v[],int n,double time)
{
    double m,p;
    m = x[0] - v[0]*time;
    p = x[0] + v[0]*time;                   
    for(int i=0;i<n;i++)
    {
        double a = v[i]*time;
        m = max(m , x[i]-a);
        p = min(p,x[i] + a);
    }
    return p-m>0;
}