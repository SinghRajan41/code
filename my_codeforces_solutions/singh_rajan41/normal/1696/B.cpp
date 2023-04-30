#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int arr[100001];
int n;
int solve(int arr[],int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<solve(arr,n)<<"\n";
        
    }
    return 0;
}
int solve(int arr[],int n)
{
    if(n==1)
        return arr[0] == 0 ? 0:1;
    else
    {
        bool flag = false;
        ll ans = 0;
        for(int i=0;i<n;i++)
            if(arr[i] > 0)
                {flag = true;break;}
        if(flag)
        {
            int low = 0;
            int high = n-1;
            while(low<n && arr[low] == 0)
                low++;
            while(high>=0 && arr[high]==0)
                high--;
            for(int i=low;i<=high;i++)
                if(arr[i] == 0)
                    return 2;
            return 1;
        }
        else
        {
            ans = 0;
        }
        return ans;

    }
}