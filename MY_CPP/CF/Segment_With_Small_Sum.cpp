/*Given an array of n integers ai. Let's say that the segment of this array a[l..r] (1≤l≤r≤n) is good if the sum of elements on this segment is at most s.
 Your task is to find the longest good segment.*/
//  #include<iostream>
//  #define ll long long int
//  using namespace std;
//  int main()
//  {
//     ll n,s; cin>>n>>s;
//     ll l= 0,x=0,res = 0;
//     ll arr[n];  
//     for(int i=0;i<n;i++)    cin>>arr[i];
//     for(ll r = 0;r<n;r++)
//     {
//         x += arr[r];
//         while(x > s)
//         {
//             x -= arr[l++];
//         }
//         res = max(res , r-l+1);
//     }
//     cout<<res<<"\n";
//     return 0;
// }
//////////     APPROACH - 2////////////////
#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,s;     cin>>n>>s;
    ll arr[n+1];  for(int i=1;i<=n;i++)    cin>>arr[i];
    ll pre[n+1];    pre[0] = 0;
    for(int i=1;i<=n;i++)   pre[i] = pre[i-1] + arr[i];
    ll low,mid,high,res = 0;
    low = 0;    high = n;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        //Check if it is possible to have a subarray
        //of length mid and sum <= s
        bool possible = false;
        for(int i=mid;i<=n;i++)
        {
            if(pre[i] - pre[i-mid] <= s)
            {
                possible = true;
            }
        }
        if(possible)
        {
            res = mid;low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<res<<"\n";
    return 0;
}