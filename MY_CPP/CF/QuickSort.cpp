#include<iostream>
using namespace std;
void solve();
int main()
{
    int t;  cin>>t;
    while(t--)
        solve();
    return 0;
}
void solve()
{
    int n,k;  cin>>n>>k; int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int a  = 0,c=0;
    for(int i=0;i<n;i++)
    {
        if(a+1 == arr[i])
            a = arr[i];
        else
            c++;
    }
    cout<<(c + k -1)/k<<"\n";
}