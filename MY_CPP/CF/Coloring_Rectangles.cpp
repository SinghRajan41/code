#include<iostream>
using namespace std;
void solve();
int main()
{
    int t;  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
int compute(int a,int b)
{
    int ans = 0;
    ans += a*(b/3);
    if(ans%3 == 1)
    {
        ans += (a/2);
    }
    else
    {
        b = b%3;
        ans += b*(a/3);
        a = a%3;
        ans += a;
    }
    return ans;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    int ans1 = compute(a,b);
    int ans2 = compute(b,a);
    cout<<min(ans1 , ans2)<<"\n";
}