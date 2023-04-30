#import<bits/stdc++.h>
using namespace std;
int a,b,c,r,t;
main()
{
 for(cin>>t;t--;)
 {
  cin>>a>>b>>c>>r;
  if(a>b)swap(a,b);
  cout<<b-a-max(min(b,c+r)-max(a,c-r),0)<<endl;
 }
}