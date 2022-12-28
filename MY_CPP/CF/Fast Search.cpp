#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<set>
#include<cstdlib>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr , arr+n);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int l,r,low,mid,high,ub,lb;
        cin>>l>>r;
        low = 0;
        high = n-1;
        lb = n;
        while(low<=high)
        {
            mid = (low + high)>>1;
            if(arr[mid] >= l)
            {
                lb = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ub = lb;
        low = 0;
        high = n-1;
        while(low<=high)
        {
            mid = (low + high)>>1;
            if(arr[mid] <= r)
            {
                ub = mid + 1;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout<<(ub - lb)<<" ";
    }
    return 0;
}

