#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
int arr[300001];
int n;
void solve(ll a, ll b, ll c)
{
    ll new_a = b - (c - b);
    if(new_a >= a && new_a % a == 0 && new_a != 0) {
        cout << "YES\n";
        return;
    }

    ll new_b = a + (c - a)/2;
    if(new_b >= b && (c-a)%2 == 0 && new_b % b == 0 && new_b != 0) {
        cout << "YES\n";
        return;
    }

    ll new_c = a + 2*(b - a);
    if(new_c >= c && new_c % c == 0 && new_c != 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,x;
        cin>>a>>b>>c;
        solve(a,b,c);
    }
    return 0;
}