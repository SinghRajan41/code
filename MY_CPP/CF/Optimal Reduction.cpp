#include<iostream>
#include<vector>
#include<queue>
#include<set>
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
    int t = 1;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
int solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int Max,idx;
    idx = -1;
    Max = -1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > Max)
        {
            Max = arr[i];
            idx = i;
        }
    }
    //cout<<idx<<" "<<arr[idx]<< " ";
    for(int i=idx;i<n;i++)
    {
        if(i+1<n && arr[i+1]>arr[i])    return 0;
    }
    for(int i=idx;i>=0;i--)
    {
        if(i-1>=0 && arr[i-1] > arr[i]) return 0;
    }
    return 1;
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


