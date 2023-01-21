// #include<iostream>
// using namespace std;
// #define ll long long int
// #define print(arr) for(int i=0;i<=r;i++){for(int j=0;j<=c;j++)  cout<<arr[i][j]<<" ";cout<<"\n";}
// int main()
// {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
//     int r,c;    cin>>r>>c;
//     ll arr[r+1][c+1];
//     for(int i=1;i<=r;i++)
//         for(int j=1;j<=c;j++)
//             cin>>arr[i][j];
//     ll d[r+1][c+1];
//     for(int i=0;i<=r;i++)   for(int j=0;j<=c;j++)   d[i][j] = 0;
//     for(int i=0;i<=r;i++)
//         d[i][0] =  arr[i][0] = 0;
//     for(int i=0;i<=c;i++)
//         d[0][i] = arr[0][i] = 0;
//     for(int i=1;i<=r;i++)
//         for(int j=1;j<=c;j++)
//             d[i][j] = arr[i][j] - arr[i][j-1];
//     ll dd[r+1][c+1];
//     for(int i=0;i<=r;i++)   for(int j=0;j<=c;j++)   dd[i][j] = 0;
//     int q;
//     cin>>q;
//     for(int i=0;i<q;i++)
//     {
//         ll x1,y1,x2,y2,x;
//         cin>>x1>>y1>>x2>>y2>>x;
//         dd[x1][y1] += x;
//         if(x2 + 1<=r)
//             dd[x2 + 1][y1] -= x;
//         if(y2 + 1<= c)
//             dd[x1][y2 + 1] -= x;
//         if((x2 +1 <=r) && (y2 + 1<= c))
//             dd[x2 +1][y2 +1] += x; 
//     }
    
//     for(int j=1;j<=c;j++)
//     {
//         for(int i=1;i<=r;i++)
//             dd[i][j] += dd[i-1][j];
//     }
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)
//             d[i][j] += dd[i][j];
//     }
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)
//         {
//             d[i][j] += d[i][j-1];
//             cout<<d[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
#define ll long int 
#define print(arr) for(int i=0;i<=r;i++){for(int j=0;j<=c;j++){cout<<arr[i][j]<<" ";}cout<<"\n\n";}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,m,q,x1,y1,x2,y2,x; cin>>n>>m;
    int r= n;   int c = m;
    ll arr[n+1][m+1],d[n+1][m+1],dd[n+1][m+1];
    
    for(int i=1;i<=n;i++)   for(int j=1;j<=m;j++)       cin>>arr[i][j];
    for(int i=0;i<=n;i++)   for(int j=0;j<=m;j++)       dd[i][j] = 0;
    for(int i=0;i<=n;i++)   arr[i][0] = d[i][0] =   dd[i][0]= 0;
    for(int i=0;i<=m;i++)   arr[0][i] = d[0][i] =   dd[i][0]= 0;
    for(int i=1;i<=n;i++)   for(int j=1;j<=m;j++)   d[i][j] = arr[i][j] - arr[i][j-1];
    cin>>q;
    for(int i=0;i<q;i++){   cin>>x1>>y1>>x2>>y2>>x; dd[(x1)][(y1)] += x; if(x2 +1<=r && y2 +1<=c)dd[(x2)+1][(y2)+1] += x;if(x2+1<=r)dd[(x2)+1][y1] -=x;if(y2 +1<=c)dd[(x1)][(y2)+1] -=x;   }
    for(int j=1;j<=c;j++)   for(int i=1;i<=r;i++)   dd[i][j] += dd[i-1][j];
    for(int i=1;i<=r;i++)   for(int j=1;j<=c;j++)   d[i][j] += dd[i][j];
    for(int i=0;i<=n;i++)   arr[i][0] = d[i][0] = 0;
    for(int i=0;i<=m;i++)   arr[0][i] = d[0][i] = 0;  
    for(int i=1;i<=r;i++)  {    for(int j=1;j<=c;j++)       d[i][j] += d[i][j-1],cout<<d[i][j]<<" ";        cout<<"\n";         }
    return 0;
}