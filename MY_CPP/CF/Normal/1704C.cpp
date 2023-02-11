#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n,m;;
cin>>n>>m;
int arr[m];
for(int i=0;i<m;i++){
cin>>arr[i];
}
sort(arr,arr+m);
vector<int>v;
for(int i=0;i<m-1;i++){
v.push_back(arr[i+1]-arr[i]-1);
}
v.push_back(arr[0]+n-arr[m-1]-1);
sort(v.begin(),v.end());
int k=0;
int l=0;
for(int i=v.size()-1;i>=0;i--){
int x=v[i];
x-=(l*2);
if(x<=0)break;
k+=(x-1);
if(x==1)k++;
l+=2;
}
cout<<n-k<<endl;
}
return 0;
}