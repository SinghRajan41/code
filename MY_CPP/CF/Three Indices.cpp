#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
bool solve();
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
bool solve()
{
    int n,k;
    cin>>n;
    int arr[n],idx[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        idx[arr[i]] = i;
    }
    int mid,low,high;
    low = mid = high = -1;
    for(int i=1;i<n-1;i++)
    {
        mid = i;
        for(int j=0;j<n;j++)
        {
            if(j == i)
                continue;
            else
            {
                if(arr[j] < arr[i] && j<i)
                    low = j;
                if(arr[j] < arr[i] && j>i)
                    high = j;

            }
        }
        if(low != -1 && high != -1 && mid != -1)
        {
            cout<<"YES\n";
            cout<<(low + 1)<<" "<<mid + 1<<" "<<(high + 1)<<"\n";
            return true;
        }
        low = high = mid = -1;
    }
    cout<<"NO\n";
    return false;

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
