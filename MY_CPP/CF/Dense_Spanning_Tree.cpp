#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
ll v,e;
struct edge{ll u;ll v;ll w;};
edge edges[(int)1e4+1];
bool cmp(edge a , edge b)   {return a.w < b.w;}
class dsu
{
    public:
    ll parent[1001],size[1001];
    dsu(){for(int i=0;i<1001;i++)   parent[i] = i , size[i] = 1;}
    bool Union(ll a,ll b);
    ll find(ll a);
};
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    cin>>v>>e;
    for(int i=0;i<e;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    bool found = false; ll ans = INT32_MAX;    ll low = 0;    ll m  = e;
    sort(edges , edges + m , cmp);
    while(low <= (m-v+1) )
    {
        ll high = low; ll curMin = INT32_MAX; ll curMax = INT32_MIN; ll curDiff = INT32_MAX;ll count = 0;
        bool included[v+1]; for(int i=0;i<=v;i++)   included[i] = false;
        dsu d;
        while(high < m)
        {
            if(d.Union(edges[high].u , edges[high].v))  {curMin = (curMin < edges[high].w ? curMin : edges[high].w);   curMax = (edges[high].w > curMax ? edges[high].w : curMax);   curDiff =  curMax - curMin;    }
            high++;
        }
        for(int i=1;i<=v;i++)   count = max(count , d.size[i]);
        if(count == v)  {   ans = min(ans , curDiff);   found = true;     }
        low++;
    }
    if(found)   {   cout<<"YES\n";  cout<<ans<<"\n";    }
    else{   cout<<"NO\n";   }
    return 0;
}
bool dsu::Union(ll a,ll b)
{
    a = find(a);    b = find(b);
    if(a^b) {   if(size[b] > size[a])   swap(a,b);  parent[b] = a;  size[a] += size[b]; return true;    }
    return false;
}
ll dsu::find(ll a)    {   return parent[a] == a ? a : parent[a] = find(parent[a]);    }
                 //if(!included[edges[high].u])    included[edges[high].u] = true , count++;
                //if(!included[edges[high].v])    included[edges[high].v] = true , count++;           