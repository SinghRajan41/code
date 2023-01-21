#include<iostream>
#define ll long long int
using namespace std;
struct item  {  ll l,r,x;   };
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,m,k;   cin>>n>>m>>k;
    ll arr[n+1];    arr[0] = 0;    for(int i=1;i<=n;i++)   cin>>arr[i];
    item ops[m+1];
    for(int i=1;i<=m;i++)   cin>>ops[i].l>>ops[i].r>>ops[i].x;
    ll d[m+1];for(int i=0;i<=m;i++) d[i] = 0;
    for(int i=0;i<k;i++)    {   int x,y;    cin>>x>>y;  d[x]++; if(y+1<=m)  d[y+1]--;   }
    for(int i=1;i<=m;i++)   d[i] = d[i-1] + d[i];
    ll dd[n+1]; dd[0] = 0;
    for(int i=1;i<=n;i++)   dd[i] = arr[i] - arr[i-1];
    for(int i=1;i<=m;i++)   {  dd[ops[i].l]+=(d[i]*ops[i].x);   dd[ops[i].r+1]-=(d[i]*ops[i].x);   }
    for(int i=1;i<=n;i++)   dd[i] = dd[i] + dd[i-1], cout<<dd[i]<< " ";
    return 0;
}