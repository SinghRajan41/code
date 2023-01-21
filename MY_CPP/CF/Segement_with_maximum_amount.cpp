#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n;  cin>>n;
    ll arr[n+1];    arr[0] = 0;    for(int i=1;i<=n;i++)   cin>>arr[i];
    ll preSum[n+1]; preSum[0] = 0;  for(int i=1;i<=n;i++)   preSum[i] = preSum[i-1] + arr[i];
    ll preMin[n+1]; preMin[0] = 0;  
    for(int i=1;i<=n;i++)
    {
        int idx = preMin[i-1];
        if(preSum[idx] < preSum[i]) preMin[i] = idx;
        else    preMin[i] = i;
    }
    ll l,r,res;
    res = INT32_MIN;    l = r = -1;
    for(int i=1;i<=n;i++)
    {
        if(i == preMin[i])
        {
            if(arr[i] > res)
            {
                res = arr[i];
                l = r = i;
            }
        }
        else
        {
            int a,b;
            a = preMin[i];
            b = i;
            if(preSum[b] - preSum[a] > res)
            {
                res = preSum[b] - preSum[a];
                l = a+1;
                r = b;
            }
        }
    }
    cout<<l<<" "<<r<<" "<<res<<"\n";
    return 0;
}