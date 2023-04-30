#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<set>
#include<cstdlib>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
void init_sp();
ll solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return  0;
}
ll solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    
        cin>>arr[i];
    int a = 0;
    int b = 1e9;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i] < arr[i+1])
        {
            b = b<((arr[i] + arr[i+1])>>1) ? b:((arr[i] + arr[i+1])>>1);
        }
        else if(arr[i] > arr[i+1])
        {
            a = a>((arr[i] + arr[i+1]+1)>>1) ? a:((arr[i] + arr[i+1]+1)>>1);
        }
    }
    return a>b ? -1 : a;
}