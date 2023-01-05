/*
You are given an undirected connected graph on n vertices and m edges. 
For each edge, you know the cost of deletion. 
You want to delete as many edges as possible so that the graph remains connected and the total cost of deleted edges does not exceed s.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;
struct edge{int u;int v;int w;int idx;};
ll n,m,s,parent[(int)5e4+1],Size[(int)53e4+1],cost = 0;
edge edges[(int)1e5+1];
vector<int> res;
bool cmp(edge a,edge b){    return a.w < b.w;   }
ll fn(ll a){     return parent[a] == a ? a : parent[a] = fn(parent[a]);   }
bool un(ll a,ll b){a = fn(a);   b = fn(b);if(a^b){if(Size[b] > Size[a]) swap(a,b);parent[b] = a;Size[a]+=Size[b];return true;}return false;}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL); cin>>n>>m>>s;
    for(int i=0;i<=n;i++)   parent[i] = i , Size[i] = 1;
    for(int i=0;i<m;i++)    cin>>edges[i].u >> edges[i].v >> edges[i].w , edges[i].idx = i+1;
    sort(edges , edges + m , cmp);
    bool deleteable[m+1];   for(int i=0;i<=m;i++)   deleteable[i] = true;
    for(int i=m-1;i>=0;i--){    if(un(edges[i].u , edges[i].v)) {   deleteable[edges[i].idx] = false;   }   }
    for(int i=0;i<m;i++){   if(deleteable[edges[i].idx] && ((cost + edges[i].w ) <= s)) {   res.push_back(edges[i].idx);    cost += edges[i].w; }   }
    cout<<res.size()<<"\n"; for(auto i:res)     cout<<i<<" ";
    return 0;
}































// #include<iostream>
// #include<algorithm>
// #include<vector>
// #define ll long long int
// using namespace std;
// struct edge{int u;int v;int w;int idx;};
// ll n,m,s,parent[(int)5e4+1],Size[(int)53e4+1],cost = 0;
// edge edges[(int)1e5+1];
// vector<int> res;
// bool cmp(edge a,edge b){    return a.w < b.w;   }
// ll fn(ll a){     return parent[a] == a ? a : parent[a] = fn(parent[a]);   }
// bool un(ll a,ll b){a = fn(a);   b = fn(b);if(a^b){if(Size[b] > Size[a]) swap(a,b);parent[b] = a;Size[a]+=Size[b];return true;}return false;}
// int main()
// {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL); cin>>n>>m>>s;
//     for(int i=0;i<=n;i++)   parent[i] = i , Size[i] = 1;
//     for(int i=0;i<m;i++)    cin>>edges[i].u >> edges[i].v >> edges[i].w , edges[i].idx = i+1;
//     sort(edges , edges + m , cmp);
//     bool deleteable[m+1];   for(int i=0;i<=m;i++)   deleteable[i] = true;
//     for(int i=m-1;i>=0;i--)
//     {
//         if(un(edges[i].u , edges[i].v))
//         {
//             deleteable[edges[i].idx] = false;
//         }
//     }
//     for(int i=0;i<m;i++)
//     {
//         if(deleteable[edges[i].idx] && ((cost + edges[i].w ) <= s))
//         {
//             res.push_back(edges[i].idx);
//             cost += edges[i].w;
//         }
//     }
//     cout<<res.size()<<"\n"; for(auto i:res)     cout<<i<<" ";
//     return 0;
// }