#include<iostream>
using namespace std;
bool solve();
#define ll long long int
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
bool solve()
{
    ll c1,c2,c3,a1,a2,a3,a4,a5,em;
    cin>>c1>>c2>>c3>>a1>>a2>>a3>>a4>>a5;
    if((c1+c2+c3)>=(a1+a2+a3+a4+a5) && c1>=a1 && c2>=a2 && c3>=a3)
    {
        em = c1-a1;
        if(em >= a4)    a4 = 0;
        else            a4-=em;
        em = c2 - a2;
        if(em >= a5)    a5 = 0;
        else    a5 -= em;
        if(a5 + a4 <= (c3 - a3))
            return true;
        else
            return false;
    }
    return false;

}