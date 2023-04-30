#include<iostream>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        cout<<n-max(0,n%k-k/2)<<"\n";
    }
    return 0;
}