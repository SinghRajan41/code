/*
There are several roads between cities 1, 2, ..., n. 
The length of each road is known. The road network is connected, i.e., 
there is a path between any pair of cities. Gas stations are located only in the cities. 
You have to calculate what is the maximal distance that the car should be 
able to pass in order to have no problems driving between cities.
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct edge {int u;int v;int w;};
edge edges[(int)4e5+1];
bool Union(int a,int b);
int parent[1501],Size[1501];
int find(int a);
bool cmp(edge a,edge b);
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)   parent[i] = i , Size[i] = 1;
    for(int i=0;i<k;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    int ans = -1;
    sort(edges , edges + k , cmp);
    for(int i=0;i<k;i++)
    {
        int a = edges[i].u; int b = edges[i].v; int w = edges[i].w;
        if(Union(a,b))
        {
            ans = max(ans , w);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
bool cmp(edge a,edge b)
{
    return a.w < b.w;
}
int find(int a)
{
    if(parent[a] == a)  return a;
    else    return parent[a] = find(parent[a]);
}
bool Union(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a^b)
    {
        if(Size[b] > Size[a])
            swap(a,b);
        parent[b] = a;
        Size[a] += Size[b];
        return true;
    }
    return false;
}