
#include<iostream>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
ll solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return  0;
}
ll solve()
{
    int r,c;
    cin>>r>>c;
    bool arr[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            arr[i][j] = false;
    for(int i=0;i<r;i++)
        arr[i][0] = true;
    for(int i=0;i<c;i++)
        arr[r-1][i] = true;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)    
            cout<<(arr[i][j] ? 'B' :'W');
        cout<<"\n";
    }
    return 0;
}