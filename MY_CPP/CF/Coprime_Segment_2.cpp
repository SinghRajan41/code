/*
Segment Tree Approach
Given an array of n integers ai. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good if the GCD of all numbers on this segment is 1.
 Your task is to find the shortest good segment.
*/
#include<iostream>
#define ll long long int
using namespace std;
ll n;
ll arr[(int)1e5+1];
ll gcd(ll a,ll b){  return a==0 ? b : gcd(b%a , a); }
class segTree
{
    public:
    ll tree[(int)4e5+4];
    segTree()   {   initSegTree(0 , n-1 , 0);   }
    ll initSegTree(int low , int high ,int i)
    {
        if(low > high)  return 1;
        if(low == high)    return tree[i] = arr[low];     
        else        return tree[i] = gcd(initSegTree(((low + high) >> 1) +1 , high , 2*i+2) , initSegTree(low ,((low + high) >> 1), 2*i+1));
    }
    ll _query(int low,int high,int l,int r,int i)
    {
        if(l>r) return -1;
        else if(l==low && r== high) return tree[i];
        else
        {
            int mid = (low + high)>>1;
            if(mid>=l && mid<=r)
            {
                ll a = _query(low,mid,l,mid,2*i+1); ll b = _query(mid+1,high,mid+1,r,2*i+2);
                if(a != -1 && b!=-1)    return gcd(a,b);
                if(a==-1 || b==-1)  return a==-1 ? b : a;
                else    return -1;
            }
            else if(r<=mid) return _query(low,mid,l,r,2*i+1);
            else    return _query(mid+1,high,l,r,2*i+2);
        }
    }
    ll query(int l,int r)   {   return _query(0,n-1,l,r,0); }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    cin>>n; for(int i=0;i<n;i++)    cin>>arr[i];
    int l,r,len = n,ans = -1; r = l = 0;
    segTree s;
    for(;l<n;l++)
    {
        while(r<n && s.query(l,r) != 1)     r++;
        if(r<n && l<=r)  {   len = min(len , r-l+1); ans = len;  }
    }
    cout<<ans<<"\n";
    return 0;
}