#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[100001];
void init();
bool isPrime(ll n);
int  solve();
int gcd(int a,int b);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
int solve()
{
    int n;
    cin>>n;
    int arr[n];
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        m[arr[i]]++;
    }


    for(int i=0;i<n;i++)
    {
        if(m[arr[i]]&1 && m[arr[i]] == 1)
        {
                cout<<"-1\n";
                return 0;
        }
    }
    int low,high;
    low = high = 0;
    while(high < n)
    {
        while(high<n && arr[high] == arr[low])
            high++;
        if(!((high-low)&1))
        {
            //even
            for(int i=high-1;i>=low;i--)
            {
                cout<<i+1<<" ";
            }
        }
        else
        {
            //odd
            cout<<high<<" ";
            for(int i=low;i<high-1;i++)
            {
                cout<<i+1<<" ";
            }
        }
        low = high;
    }
    nl;
    return 0;
}
int gcd(int a,int b)
{
    if(a == 0)
        return b;
    else
    {
        return gcd(b%a , a);
    }
}
bool isPrime(ll n)
{
    if((!(n&1)) && n!=2)
        return false;
    else
    {
        for(int i=3;i*i<=n;i+=2)
            if(n%i==0)  return false;
    }
    return true;
}

void init()
{
    for(int i=0;i<100001;i++)   seive[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(seive[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                seive[j] = false;
            }
        }
    }
}