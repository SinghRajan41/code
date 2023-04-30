#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,q;
    cin>>n>>q;
    int arr[n];
    long long int sum[n+1];
    sum[0] = 0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr + n );
    for(int i=1;i<=n;i++)
    {
        sum[i] = arr[i-1] + sum[i-1];
    }
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        ll a = sum[n-x+y] - sum[n-x];
        cout<<a<<endl;
    }
    return 0;
}