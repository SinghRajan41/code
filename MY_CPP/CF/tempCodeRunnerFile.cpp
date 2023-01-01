#include<iostream>
#include<vector>
using namespace std;
const int inf = 2e9;
class dsu
{
    public:
    int *parent,n,*size;
    vector<vector<int>> f;
    dsu()   {n = 2e5+1;parent = new int[n];size = new int[n];for(int i=0;i<n;i++){vector<int> temp(1,i);f.push_back(temp);parent[i] = i;size[i] = 1;}}
    int findParent(int a){  return (a==parent[a] ? a : (parent[a] = findParent(parent[a])));}
    bool Union(int a,int b)
    {   
        a = findParent(a);  b = findParent(b);
        if(a^b){    if(b==1 || (size[b] > size[a] && a != 1)){  swap(a,b);  }parent[b] = a;size[a]+=size[b];for(auto x:f[b])f[a].push_back(x);f[b].clear();return true;  }
        return false;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  dsu d;
    int n,m;cin>>n>>m;
    vector<pair<int,int>> h(n+1),hf(n+1),s(m+1);
    vector<int>  time(n+1,-1);
    for(int i=1;i<=n;i++)   {   cin>>h[i].first>>h[i].second;hf[i].first = h[i].first;hf[i].second = h[i].second;   }
    for(int i=1;i<=m;i++)   cin>>s[i].first>>s[i].second;
    for(int i=1;i<=m;i++)
    {
        if(s[i].second == 1)
            hf[s[i].first].first = -1;
        else
            hf[s[i].first].second = -1;
    }
    for(int i=1;i<=n;i++)
    {
        int a = i;int b = hf[i].first;
        if(b != -1) d.Union(a,b);b = hf[i].second;if(b != -1)d.Union(a,b);
    }
    
    for(int i=m;i>=1;i--)
    {
        int a = s[i].first;int b;
        if(s[i].second == 2)    b = h[a].second;
        else    b = h[a].first;
        if(b != -1){a = d.findParent(a);b = d.findParent(b);if(a != 1){ for(auto x:d.f[a])  time[x] = i-1;}if(b != 1){ for(auto x:d.f[b])  time[x] = i-1;}d.Union(a,b);}
    }
    for(int i=1;i<=n;i++)       cout<<time[i]<<"\n";
    return 0;
}
