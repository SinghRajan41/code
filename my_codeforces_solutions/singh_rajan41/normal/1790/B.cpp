#include<bits/stdc++.h>
using namespace std;
int main() 
{int a;
cin>>a;
while(a--)
{int n ,s ,r;
cin>>n>>s>>r;cout<<s-r<<" ";
for (int i = 0; i < n-1; i++) 
{cout<<(r+i)/(n-1)<<" ";}
cout<<endl;}
}