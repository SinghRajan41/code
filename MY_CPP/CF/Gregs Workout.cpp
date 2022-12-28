#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    int t = 1;
	//cin>>t;
	while(t--)
	{
        solve();
    }
	
	return 0;
}
int solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int a,b,c;
    a = 0;
    b = 0;
    c = 0;
    for(int i=0;i<n;i+=3)
        a+=arr[i];
    for(int i=1;i<n;i+=3)
        b+=arr[i];
    for(int i=2;i<n;i+=3)
        c+=arr[i];
    if(a>b && a>c)
        cout<<"chest";
    else if(b>a && b>c)
        cout<<"biceps";
    else 
        cout<<"back";
    
    return 0;
}