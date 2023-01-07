#include<iostream>
#include<string>
using namespace std;
bool solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
        cout<<(solve() ?  "YES\n"  : "NO\n");
    return 0;
}
bool solve()
{
    int n;  cin>>n; string s;   cin>>s;
    int a,b;    a = b = 0;
    for(int i=0;i<n;i++)    
    {
        if(s[i] == 'T') a++;
        else            b++;
    }
    if(a != 2*b)    return false;
    a = b = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'T')     a++;
        else                {b++;   }
        if(a < b)return false;
    }
    a = b = 0;
    for(int i=0;i<n/2;i++)
        swap(s[i] , s[n-1-i]);
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'T')     a++;
        else                {b++;   }
        if(a < b)           return false;
    }
    return true;
}
