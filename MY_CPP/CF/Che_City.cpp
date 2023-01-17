/*
This is a problem from the Russia High School Team Programming Contest 2013
In the center of Che city there is a pedestrian street, one of the most popular walking places for city residents.
 This street is very pleasant to walk, because along the street there are n funny monuments.
The girl Masha from the city of Che likes two boys from her school, 
and she cannot make a choice between them. To make the final decision, she decided to date both boys at the same time.
 Masha wants to choose two monuments on the pedestrian street, near which the boys will be waiting for her. 
 At the same time, she wants to choose such monuments so that the boys do not see each other. Masha knows that because of the fog, 
 the boys will see each other only if they are on distance not more than r meters. 
 Masha got interested in how many ways there are to choose two different monuments for organizing dates.


 
//                         BINARY SEARCH                         //
//                         BINARY SEARCH                         //
//                         BINARY SEARCH                         //
*/
// #include<iostream>
// #define ll long long int
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
//     ll n,r; cin>>n>>r;
//     ll arr[n];  for(int i=0;i<n;i++)    cin>>arr[i];
//     ll ans = 0;
//     for(int i=0;i<n;i++)
//     {
//         ll key = arr[i] + r + 1;
//         int low = i+1;
//         int high = n-1;
//         int pos = n;
//         while(low <= high)
//         {
//             int mid = (low + high) >> 1;
//             if(arr[mid] >= key)
//             {
//                 pos = mid;
//                 high = mid - 1;
//             }
//             else    
//             {
//                 low = mid + 1;
//             }
//         }
//         ans += (n - pos);
//     }
//     cout<<ans<<"\n";
//     return 0;
// }
//############$$$$$$$$$$$$$$$ APPROACH 2 $$$$$$$$$$$$$$$$#################
//############$$$$$$$$$$$$$$$ APPROACH 2 $$$$$$$$$$$$$$$$#################
//                          TWO POINTERS                                //
//                          TWO POINTERS                                //
#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,limit; cin>>n>>limit;
    ll arr[n];  for(int i=0;i<n;i++)    cin>>arr[i];
    ll ans = 0;
    ll r = 0;
    for(ll l=0;l<n;l++)
    {
        while(r<n && arr[r]-arr[l] <= limit)
            r++;
        if(r<n && arr[r] - arr[l] > limit)
            ans += n-r;
    }
    cout<<ans<<"\n";
    return 0;
}