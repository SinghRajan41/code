#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<cstdlib>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool f(int arr[],int n,int k,double x);
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    double low = 0;
    double high = 1e8;
    for(int i=0;i<100;i++)
    {
        double mid = (low + high)/2.0;
        if(f(arr,n,k,mid))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout<<setprecision(20)<<low<<"\n";
    return 0;
}
bool f(int arr[],int n,int k,double x)
{
    int a = 0;
    for(int i=0;i<n;i++)
    {
        a +=floor(1.0*arr[i]/x);
    }
    return a>=k;
}

