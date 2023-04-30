#include<bits/stdc++.h>
int t,n,i,s,m,a[100001];
int p(int n)
{
  return pow(ceil(sqrt(n)),2);
}
main()
{
  for(std::cin>>t;t--;)
  {
    for(std::cin>>n,s=p(m=i=--n);i>=0;(s-i)<=m?a[i--]=s-i:s=p(m=i));
    for(;++i<=n;printf("%d%c",a[i]," \n"[i==n]));
  }
}