#include<iostream>
using namespace std;
int main()
{
    int t;  cin>>t;
    while(t--)
    {
        int n;  cin>>n;
        if(n&1)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<"0 "<<n/2<<" "<<n/2<<"\n";
        }
    }
    return 0;
}