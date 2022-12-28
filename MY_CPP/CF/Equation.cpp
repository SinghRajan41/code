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
    double c;
    cin>>c;
    double low = 0.0;
    double high = 1e5;
    for(int i=0;i<150;i++)
    {
        double mid = (low + high)/2.0;
        double val = mid*mid + sqrt(mid);
        if(val>=c)
        {   
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout<<setprecision(16)<<high<<"\n";
    return 0;
}

