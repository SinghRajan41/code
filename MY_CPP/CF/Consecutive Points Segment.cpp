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
        cout<<(solve() ? "YES\n" : "NO\n");
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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int prev = arr[0] - 1;
    bool c1,c2,c3;
    c1 = c2 = c3 = true;
    for(int i=1;i<n;i++)
    {
        if(arr[i] - prev  <=2 && arr[i] - prev >=0)
        {
            prev++;
        }
        else
        {
            c1 = false;
            break;
        }
    }
    int prev2 = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i] - prev2  <=2 && arr[i] - prev2 >=0)
        {
            prev2++;
        }
        else
        {
            c2 = false;
            break;
        }
    }
    int prev3 = arr[0] + 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] - prev3  <=2 && arr[i] - prev3 >=0)
        {
            prev3++;
        }
        else
        {
            c3 = false;
            break;
        }
    }
    return (c1)|(c2)|(c3);
}


