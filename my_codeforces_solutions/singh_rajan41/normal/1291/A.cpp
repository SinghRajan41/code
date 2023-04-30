#include <bits/stdc++.h>
using namespace std;
int main()
{int t;
 cin>>t;
 while(t--)
 {int n,i,c=0;
  cin>>n;
  string s;
  cin>>s;
  for(i=0;i<n&&c<11;i++)
   if(s[i]&1)
    c=c*10+s[i]-48;
  if(c<11)
   cout<<"-1\n";
  else
   cout<<c<<'\n';
 }
}