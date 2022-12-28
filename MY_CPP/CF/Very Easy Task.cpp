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
    ll n,x,y;
    cin>>n>>x>>y;
    if(n==1)
    {
        cout<<min(x,y)<<"\n";
        exit(0);
    }
    if(x<y)
        swap(x,y);
    ll low,high;
    low = 0;
    high = max(x,y)*n;
    ll ans = 0;
    while(low<=high)
    {
        ll mid = (low + high)>>1;
        ll cps = mid/x + mid/y;
        if(cps>=n-1)
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<ans + min(x,y)<<"\n";
    return 0;
}

