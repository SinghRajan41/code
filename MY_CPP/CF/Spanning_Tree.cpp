#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{long long int u;long long int v;long long int w;};
bool cmp(edge a,edge b){    return a.w < b.w ;}
long long int *parent;
long long int find(long long int a){if(a==parent[a])    return a;else{parent[a] = find(parent[a]);return parent[a];}}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long int  cost = 0;
    long long int v,e,*size,M = 2e5+1,accepted;  cin>>v>>e;  edge edges[e];accepted = v;
    bool vis[v+1];  for(int i=0;i<=v;i++)   vis[i] = false;
    parent = new long long int[M];    size = new long long int[M];  for(int i=0;i<M;i++)    parent[i] = i , size[i] = 1;
    for(int i=0;i<e;i++)    cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges , edges + e , cmp);
    for(int i=0;i<e;i++)
    {
        int a = edges[i].u;int b = edges[i].v;  a = find(a);b = find(b);
        if(a != b)
        { 
            cost += edges[i].w;  
            if(size[b] > size[a])   swap(a,b); parent[b] = a;  size[a] += size[b];
        }
    }
    cout<<cost<<"\n";
    return 0;
}
