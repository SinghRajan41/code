#include<iostream>
#include<vector>
using namespace std;
class dsu
{
    int n,*parent,*size,*res,*pending;
    vector<vector<int>> adj;
    public:
    dsu()
    {
        n = 2e5+1;
        parent = new int[n];
        size = new int[n];
        res = new int[n];
        pending = new int[n];
        for(int i=0;i<n;i++)
        {
            vector<int> temp(1,i);
            adj.push_back(temp);
            parent[i] = i;
            size[i] = 1;
            res[i] = pending[i] = 0;
        }
    }
    void add(int a,int value);
    void join(int a,int b);
    int get(int a);
    int findParent(int a);
};
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    dsu d;
    while(q--)
    {
        string s;
        cin>>s;
        if(s[0] == 'a')
        {
            int a,b;
            cin>>a>>b;
            d.add(a,b);
        }
        else if(s[0] == 'j')
        {
            int a,b;
            cin>>a>>b;
            d.join(a,b);
        }
        else
        {
            int a;
            cin>>a;
            cout<<d.get(a)<<"\n";
        }
    }
}
void dsu::join(int a,int b)
{
    a = findParent(a);
    b = findParent(b);
    if(a^b)
    {
        if(size[b] > size[a])
            swap(a,b);
        for(auto x:adj[b])
        {
            res[x] += (pending[b] - pending[a]);
            adj[a].push_back(x);
        }
        pending[b] = 0;
        adj[b].clear();
        parent[b] = a;
        size[a] += size[b];
    }
}

int dsu::get(int a)
{
    return res[a] + pending[findParent(a)];
}
int dsu::findParent(int a)
{
    if(parent[a] == a)
        return a;
    else
        return parent[a] = findParent(parent[a]);
}
void dsu::add(int a,int value)
{
    pending[findParent(a)] += value;
}
// #include<bits/stdc++.h>
// using namespace std ;


// struct dsu{
//   int n ;
//   vector<int>p,s,del,ans;
//   vector<vector<int>>adj ;
//   dsu(int _n):n(_n){
//     p.resize(n) ;  s.assign(n,1) ;
//     del.assign(n,0) ;ans.assign(n,0) ;
//     iota(p.begin(),p.end(),0) ;
//     adj = vector<vector<int>>(n) ;
//     for(int i=0;i<n;i++)
//       adj[i].push_back(i);
//   }


//   int find(int x){
//     return (x==p[x]?x:p[x]=find(p[x])) ;
//   }



//   int qry(int A){
//     return ans[A]+del[find(A)];
//   }


//   void upd(int A,int x){
//     del[find(A)]+=x ;
//   }



//   bool join(int a,int b){
//     a=find(a),b=find(b) ;
//     if(a==b)
//       return 0  ;
//     if(s[b]>s[a])
//       swap(a,b) ;
//     for(int x:adj[b])
//       ans[x]+=del[b]-del[a] ,adj[a].push_back(x);
//     adj[b].clear() ; 
//     del[b]=0  ;
//     p[b]=a ; s[a]+=s[b] ;
//     return 1 ;
//   }
// };


// signed main()
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int n,q  ;
//   cin >> n >> q  ; 
//   dsu D(n) ;
//   while(q--){
//     int A,B;
//     string qt ;
//     cin >> qt ;
//     if(qt=="join"){
//       cin >> A >> B ;--A; --B ;
//       D.join(A,B) ;
//     }else if(qt=="add"){
//       cin >> A >> B  ;--A ;
//       D.upd(A,B) ;
//     }else{
//       cin >> A ;--A ;
//       cout << D.qry(A) << '\n' ;
//     }
//   }
// }