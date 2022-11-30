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
ll sumOfDigits(ll x)
{
    ll sum = 0;
    while(x)
    {
        sum += (x%10);
        x/=10;
    }
    return sum;
}
bool hasDistinct(ll x)
{
    ll arr[10];
    for(int i=0;i<10;i++)   arr[i] = 0;
    while(x)
    {
        arr[x%10]++;
        x/=10;
    }
    for(int i=0;i<10;i++)
    {
        if(arr[i]>=2)
            return false;
    }
    return true;
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
    else
    {
        for(int i=10;i<=50000000;i++)
        {
            ll sum = sumOfDigits(i);
            if(sum == i)
            {
                if(hasDistinct(i))
                {
                    cout<<i<<"\n";
                    return true;
                }
            }
        }
    }
    return false;
}