#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
int arr[300001];
int n;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr , arr + n);
        vector<int> a;
        ll count = 1;
        int low = 1;
        while(low < n)
        {
            if(arr[low] == arr[low-1])
            {
                count++;
            }
            else
            {
                a.push_back(count);
                count = 1;
            }
            low++;
        }
        a.push_back(count);
        sort(a.begin() , a.end());
        count = a.size();
        for(ll i = 1;i<=n;i++)
        {
            cout<<max(count , i)<< " ";
        }
        cout<<endl;
        
    }
    return 0;
}