#include<iostream>
int main()
{
    long long x,y,t;
    for(std::cin>>t;t--;std::cout<<(x-y>1?"YES\n":"NO\n"))std::cin>>x>>y;
    return 0;
}