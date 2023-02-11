#include<iostream>
#include<vector>
#include<queue>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
void solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    ll sum = 0;
    for(int i=0;i<n;i++)    sum += arr[i];
    if(sum == 0)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
       if(sum > 0)
       {
        // arrange in ascending order
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(arr[j] < arr[j+1])
                    swap(arr[j],arr[j+1]);
            }
        }
       }
       else
       {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n-1-i;j++)
                {
                    if(arr[j] > arr[j+1])
                        swap(arr[j],arr[j+1]);
                }
            }
       }
       for(int i=0;i<n;i++) cout<<arr[i]<<" ";
       cout<<"\n";
    }
}
void init()
{
    for(int i=0;i<100001;i++)   isPrime[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}