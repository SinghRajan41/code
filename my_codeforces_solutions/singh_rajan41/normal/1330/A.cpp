#include<bits/stdc++.h>
using namespace std;
int i,t,n,x,a;
main(){
for(cin>>t;t--;cout<<" "){
    cin>>n>>x;int b[204]={0};
while(n--)cin>>a,b[a]=1;
for(i=1;x>0||b[i]!=0;i++)if(b[i]==0)x--;
    cout<<i-1;
}
}