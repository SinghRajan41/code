/*Given an array of n integers ai. Let's say that the segment of this array a[l..r] (1≤l≤r≤n) is good if 
the sum of elements on this segment is at least s. Your task is to find the shortest good segment.*/
// #include<iostream>
// #include<cstdlib>
// #define ll long long int
// using namespace std;
// int main()
// {   
//     ll n,s,r,x; cin>>n>>s;
//     ll arr[n];
//     for(int i=0;i<n;i++)    cin>>arr[i];
//     x = 0;
//     for(int i=0;i<n;i++)    x += arr[i];
//     if(s  > x)
//     {
//         cout<<-1;
//         exit(0);
//     }
//     ll l =  0;  x = 0;  ll res = n;
//     for(r = 0;r<n;r++)
//     {
//         x += arr[r];
//         while(x - arr[l] >= s && l<=r)
//             x -= arr[l++];
//         if(x >= s)
//         {
//             res = min(res , r-l+1);
//         }
//     }
//     cout<<res<<"\n";
//     return 0;
// }
#include<iostream>
#include<cstdlib>
#define ll unsigned long long int
using namespace std;
int main()
{
    ll n,s,res,low,high,mid,possible,x;
    cin>>n>>s;
    ll arr[n+1],pre[n+1];  for(int i=1;i<=n;i++)   cin>>arr[i]; pre[0]=0;
    for(int i=1;i<=n;i++)   pre[i] = pre[i-1] + arr[i];
    low = x = 0;    res = n;    high = n-1;
    if(s > pre[n])
    {
        cout<<-1;exit(0);
    }
    while(low <= high)
    {
        mid = (low + high) >> 1;
        possible = 0;
        for(int i=mid ;i <= n;i++)
        {
            if(pre[i] - pre[i-mid] >= s)
            {
                possible = 1;
            }
        }
        if(possible)
        {
            high = mid - 1;
            res = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<res;
    return 0;
}