//Given n houses in line and k colours, find the number of ways of coloring n houses using k colors such that not more than two homes have same color
#include<iostream>
#define ll long long int
using namespace std;
#define M 1000000007
int main()
{
    ll n,k;
    cin>>n>>k;
    ll same[n+1],diff[n+1];
    same[0] = same[1] = diff[0] = diff[1] = 0;
    same[2] = k;
    diff[2] = k*(k-1);
    for(int i=3;i<=n;i++)
    {
        same[i] = diff[i-1];
        diff[i] = ((k-1)%M * (same[i-1] + diff[i-1])%M)%M;
    }
    cout<<(same[n] + diff[n])%M;
    return 0;
}