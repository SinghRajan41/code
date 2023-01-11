#include<bits/stdc++.h>
using namespace std;
int v,e;
vector<vector<int>> g;
vector<vector<bool>> vis;
vector<bool> nodeVis;
void init();
void dfs(int u,vector<int> path);
void printPath(vector<int> &path);
bool verify(vector<int> &path);
int main()
{
    init();
    for(int i=1;i<=v;i++)
    {
        vector<int> path;
        dfs(i , path);
    }
    return 0;
}
bool verify(vector<int> &path)
{
    int temp[v+1];
    for(int i=0;i<=v;i++)   temp[i] = 0;
    for(auto x:path)
        temp[x]++;
    int x = 0;
    for(int i=1;i<=v;i++)
        if(temp[i])
            x++;
    int a = 0;
    for(int i=1;i<=v;i++)
        for(int j=i+1;j<=v;j++)
            if(vis[i][j])
                a++;
    return x == v && a == e;
}
void dfs(int u , vector<int> path)
{
    path.push_back(u);
    if(verify(path))
    {
        printPath(path);
    }
    else
    {
        for(int vv=1;vv<=v;vv++)
        {
            if(g[u][vv] && !vis[u][vv])
            {
                vis[u][vv] = vis[vv][u] = true;
                dfs(vv , path);
                vis[u][vv] = vis[vv][u] = false;
            }
        }
    }
}
void init()
{
    cin>>v>>e;
    for(int i=0;i<=v;i++)
    {
        vector<int> temp(v+1 , 0);
        vector<bool> temp2(v+1 , false);
        g.push_back(temp);
        vis.push_back(temp2);
    }
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u][v] = g[v][u] = 1;
    }
}
void printPath(vector<int> &path)
{
    for(auto i:path)
        cout<<i<<" ";
    cout<<"\n";
}