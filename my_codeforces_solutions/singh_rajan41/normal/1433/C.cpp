#include<iostream>
#include<vector>
#include<queue>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
void solve();
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    ll n,res,idx;
    res = -1;
    cin>>n;
    ll arr[n];
    idx = -1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i] > res)
        {
            res = arr[i];
            idx = i;
        }
    }
    ll ok = 0;
    for(int i=0;i<n;i++)
        if(arr[i] != arr[0])    
        {
            ok = 1;
            break;
        }
    if(ok)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i] == res)
            {
               if(i==0)
               {
                    if(i+1<n && arr[i+1] < arr[i])
                    {
                        cout<<i+1<<endl;
                        break;
                    }
               }
               else if(i == n-1)
               {
                    if(i-1 >=0 && arr[i-1]  < arr[i])
                    {
                        cout<<i+1<<endl;
                        break;
                    }
               }
               else
               {
                    if(arr[i-1] < arr[i] || arr[i] > arr[i+1] )
                    {
                        cout<<i+1<<"\n";
                        break;
                    }
               }
            }
        }
    }
    else
    {
        cout<<"-1\n";
    }
}
void init()
{
    for(int i=0;i<100001;i++)   isPrime[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}