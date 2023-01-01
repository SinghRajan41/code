#include<iostream>
using namespace std;
int *parent,n,q,a,b;char type;
bool *p;
int find(int a){    if(a==parent[a])    return a;   else{parent[a] = find(parent[a]);return parent[a];} }
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>q;  parent = new int[n+1];  p = new bool[n+2];  for(int i=0;i<=n;i++)   parent[i] = i,p[i] = true;   p[n+1] = false;
    for(int i=0;i<q;i++)
    {
        cin>>type>>a;
        if(type == '-'){    if(p[a]){   p[a] = false;   if(a != n){   b = find(a+1);  parent[a] = b;  }}}
        else{   if(p[a])    cout<<a<<"\n";  else{a = find(a);    cout<<(p[a] ? a : -1)<<"\n";}  }
    }
    return 0;
}
