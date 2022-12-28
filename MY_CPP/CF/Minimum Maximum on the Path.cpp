#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
void solve()
{
    int n,m,d;
    cin>>n>>m>>d;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    vector<int> parent(n+1,-1) , level(n+1 , 0);
    int low = 0;
    int high = 1e9+1;
    int res = -1;
    while(low <= high)
    {
        int mid = (low + high)>>1;
        //Start doing bfs
        vector<bool> visited(n+1 , false);
        for(int i=0;i<=n;i++)   visited[i] = false;
        queue<int> q;
        q.push(1);
        visited[1] = true;
        level[n] = n;
        while(!q.empty())
        {
            int u = q.front();    q.pop();
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if(!visited[v] && level[u] < d && w<=mid)
                {
                    //Push this neighbour into the queue and mark as visited
                    q.push(v);                        // push the neighbour into the queue
                    visited[v] = true;                //mark visited array as true
                    level[v] = level[u] + 1;          //update lev(u) as lev(v) + 1
                    parent[v] = u;
                }
            }
        }
        if(level[n] <= d)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(res != -1)
    {
        int x = n;
        stack<int> s;
        while(x != -1)
        {
            s.push(x);
            x = parent[x];
        }
        cout<<s.size()-1<<"\n";
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    else
    {
        cout<<"-1\n";
    }
}