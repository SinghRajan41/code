#include<iostream>
#include<string>
using namespace std;
#define ll long long int
ll solve();
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
bool palindrome(string s);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}
ll revNum(ll num)
{
    ll rev = 0;
    while(num)
    {
        rev = rev*10 + num%10;
        num /= 10;
    }
    return rev;
}
bool palindrome(string s)
{
    int n = s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i] != s[n-1-i])
            return false;
    }
    return true;
}
ll solve()
{
    string s,t;
    cin>>s;
    cin>>t;
    if(t.length() == 1)
    {
        if(t[0] == 'a')
            return 1;
        else
            return (1ll<<s.length());
    }
    else
    {
        int a = 0;
        for(int i=0;i<t.length();i++)
        {
            if(t[i] == 'a')
                a += 1;
        }
        int n = t.length();
        if(a == 0)
        {
            return (1ll<<s.length());
        }
        else
        {
            return -1;
        }
    }
}


