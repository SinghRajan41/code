#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return  0;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int Min = arr[0];
    for(int i=0;i<n;i++)
        Min = min(arr[i] , Min);
    int a = n>>1;
    for(int i=0;i<n;i++)
    {
        if(a>0 && arr[i] != Min)
        {
            a-=1;
            cout<<arr[i]<<" "<<Min<<"\n";
        }
    }
}