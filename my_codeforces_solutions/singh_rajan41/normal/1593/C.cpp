#include<bits/stdc++.h>
using namespace std;
bool good(vector<int> arr , int n , int k , int x);
void solve();
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t;  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n,k;    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<k;i++)
    {
        int temp;   cin>>temp;  arr.push_back(temp);
    }
    sort(arr.begin() , arr.end());
    int l,r,m;
    l = 0;  r = k;
    int ans = 0;
    while(l <= r)
    {
        m = (l + r)>>1;
        if(good(arr , n , k , m))
        {
            ans = m;
            l = m+1;
        }
        else
        {
            r = m-1;
        }
    }
    cout<<ans<<"\n";
}
bool good(vector<int> arr , int n,int k , int x)
{
    int mouse = 0;
    unsigned long long int t = 0;
    bool flag = true;
    for(int i=k-1;i>=0;i--)
    {
        if((t/2) < arr[i])
        {
            //If cat has not arrived, send the mouse at arr[i] to n and update time
            t += 2*(n - arr[i]);
            mouse++;
            
        }
        else
        {
            //The cat has alread arrived, and will eat the mouse present at arr[i]
            break;
        }
    }
    return mouse >= x ? true : false;
}