#include<iostream>
using namespace std;
int *parent;
int find(int a){if(parent[a] == a)  return a;else{parent[a] = find(parent[a]);return parent[a];}}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n;  cin>>n; parent = new int[n+1];  for(int i=0;i<=n;i++)  parent[i] = i;
    for(int i=0;i<n;i++){   int a;  cin>>a; a = find(a);  cout<<a<<" "; int b = a+1;    if(b>n) b = 1;  b = find(b);    parent[a] = b;  }
    return 0;
}