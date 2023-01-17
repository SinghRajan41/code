/*Dan array a. Display its array of prefix amounts. In other words, withdraw 0, a1, a1+a2, ..., a1+a2+...+an.*/
#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n;   cin>>n;
    ll pre[n+1];
    pre[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>pre[i];
        pre[i]+=pre[i-1];
    }
    for(int i=0;i<=n;i++)
        cout<<pre[i]<<" ";
    return 0;
}