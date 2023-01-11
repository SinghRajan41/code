#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
bool solve();
bool isPrime[100001];
bool cmp(int a,int b);
void init();
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

bool solve()
{
    int n;
    cin>>n;
    if(n%2 == 0)
    {
        bool f = true;
        int res[n][n];
        int low = 1;
        int high = n*n;
        for(int i=0;i<n;i++)
        {
            if(f)
            {
                bool f2 = true;
                for(int j=0;j<n;j++)
                {
                    res[i][j] = f2 ? low++ : high--;
                    f2 = f2 ? false:true;
                }
            }
            else
            {
                bool f2 = true;
                for(int j=n-1;j>=0;j--)
                {
                    res[i][j] = (!f2) ? high-- : low++;
                    f2 = f2 ? false:true;
                }
            }
            f = f ? false : true;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<res[i][j]<<" ";
            cout<<"\n";
        }
    }
    else
    {
        int res[n][n];
        int low = 1;
        int high = n*n;
        bool f = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   res[i][j] = f ? low++ : high--;  f = f ? false : true; }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<res[i][j]<<" ";
            cout<<"\n";
        }
    }
    return false;
}
bool cmp(int a,int b)
{
    return a>b;
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
