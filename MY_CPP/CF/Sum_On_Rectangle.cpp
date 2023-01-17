#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll arr[n+1][m+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>arr[i][j];
    ll pre[n+1][m+1];
    for(int i=0;i<=n;i++)   pre[i][0] = 0;
    for(int i=0;i<=m;i++)   pre[0][i] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
    int q;  cin>>q;
    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2;    cin>>x1>>y1>>x2>>y2;
        cout<<(pre[x2][y2] - pre[x2][y1 - 1] - pre[x1-1][y2] + pre[x1-1][y1 - 1])<<"\n";
    }
    return 0;
}