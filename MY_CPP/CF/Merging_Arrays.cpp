#include<iostream>
using namespace std;
int main()
{
    int n,m;    cin>>n>>m;
    int a[n] , b[m];
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];
    int i,j;    i=0;j=0;
    while(i<n && j<m)
    {
        if(a[i] < b[j])     cout<<a[i++]<<" ";
        else                cout<<b[j++]<<" ";
    }
    while(i<n)
        cout<<a[i++]<<" ";
    while(j<m)
        cout<<b[j++]<<" ";
    return 0;
}