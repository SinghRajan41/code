#include<iostream>
using namespace std;
#define ll long long int
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
bool solve(int l,int r);
bool isPrime[100001];
void init();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        cin>>s;
        for(int i=0;i<q;i++)
        {
            int l,r;
            cin>>l>>r;
            cout<<(solve(l,r) ? "YES\n" : "NO\n");
        }
        s.clear();
    }
    return 0;
}

bool solve(int l,int r)
{
    int n = s.length();
    ll zero[s.length() + 2];
    ll one[s.length() + 2];
    zero[0] = one[0] = -200;
    zero[n+1] = one[n+1] = 200;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == '0')
        {
            zero[i+1] = i;
            one[i+1] = one[i+2];
        }
        else
        {
            one[i] = i;
            zero[i] = zero[i+1];
        }
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