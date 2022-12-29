#include<iostream>
#include<vector>
using namespace std;
class dsu{
    int *parent,n;
    public:
    dsu()
    {
        n = 5e4+1;
        parent = new int[n];
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    int find(int x)
    {
        return (x==parent[x]) ? (x) : (parent[x] = find(parent[x]));
    }
    bool Union(int a,int b)
    {
        a = find(a);
        b = find(b);
        if(a^b)
        {
            parent[a] = b;
            return true;
        }
        return false;
    }
};
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
    }
    vector<pair<int,int>> qr(q);
    vector<bool> res(q),type(q);
    for(int i=0;i<q;i++)
    {
        string s;
        int x,y;
        cin>>s>>x>>y;
        qr[i] = make_pair(x,y);
        type[i] = (s=="cut");
    }
    dsu d;
    for(int i=q-1;i>=0;i--)
    {
        if(type[i])
            d.Union(qr[i].first , qr[i].second);
        else
            res[i] = (d.find(qr[i].first) == d.find(qr[i].second));
    }
    for(int i=0;i<q;i++)
    {
        if(!type[i])
            cout<<(res[i] ? "YES\n" : "NO\n"); 
    }
    return 0;
}
