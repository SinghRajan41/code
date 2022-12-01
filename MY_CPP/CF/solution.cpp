#include<iostream>
using namespace std;
bool solve();
#define ll long long int
bool hasDistinct(ll x);
ll sumOfDigits(ll x);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        if(!solve())
            cout<<"-1\n";
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
bool solve()
{
    ll x;
    cin>>x;
    if(x<=9)
    {
        cout<<x<<"\n";
        return true;
    }
    else if(x>45)
    {
        return false;
    }
    else
    {
        ll digit = 9;
        ll res = 0;
        while(x > 0)
        {
            if(digit <= x)
            {
                res = res*10 + digit;
                x -= digit;
                digit--;
            }
            else
            {
                res = res*10 + x;
                x = 0;
            }
        }
        cout<<revNum(res)<<"\n";
        return true;
    }
}


