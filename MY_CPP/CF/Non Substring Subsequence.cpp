#include<iostream>
using namespace std;
bool solve(int l,int r);
#define ll long long int
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
string s;
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
    for(int i=0;i<l-1;i++)
        if(s[i] == s[l-1])
            return true;
    for(int i=r;i<s.length();i++)
        if(s[i] == s[r-1])
            return true;
    return false;
}