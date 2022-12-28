#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
bool solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
bool solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b)
        swap(a,b);
    if(c>d)
        swap(c,d);
    if((a+c) == b && b == d)
        return true;
    else
        return false;
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
