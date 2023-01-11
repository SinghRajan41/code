#include<iostream>
#define ll unsigned long long int
using namespace std;
ll arr[(ll)1e5+1],n,k;
class segTree
{
    ll minTree[(int)4e5+4]; ll maxTree[(int)4e5+4];
    public:
    ll createMin(int low , int high , int i)
    {
        if(low > high)
            return INT64_MAX;
        else if(low == high)    {minTree[i] = arr[low];return arr[low];}
        else    {   int mid = (low + high)>>1;  ll a = createMin(low , mid , 2*i+1);ll b = createMin(mid + 1 , high , 2*i+2);   minTree[i] = min(a , b);return minTree[i];}
    }
    ll createMax(int low , int high , int i)
    {
        if(low > high)  return 0;
        else if(low == high)     {maxTree[i] = arr[low];return arr[low];}    
        else  {  int mid = (low + high) >> 1 ; return  maxTree[i] = max(createMax(low , mid , 2*i+1),createMax(mid + 1 , high , 2*i+2));}
    }
    ll createMax();
    segTree()   {   createMin(0 , n-1 , 0); createMax(0 , n-1 , 0); }
    ll getMin(int l,int r)  {   return _getMin(0 , n-1 , l , r , 0);}
    ll _getMin(int low , int high , int l , int r ,int i)
    {
        if(l > r)
            return INT64_MAX;
        if(l==low && r == high)
            return minTree[i];
        else
        {   int mid = (low + high) >> 1;
            if(mid >= l && mid <= r)    return min(_getMin(low , mid , l , mid , 2*i+1),_getMin(mid + 1 , high , mid + 1 , r , 2*i+2));
            else if(r<= mid)            return _getMin(low , mid , l , r , 2*i+1);  
            else                        return _getMin(mid+1 , high , l ,r , 2*i+2);    
        }
    }
    ll getMax(int l , int r)    {   return _getMax(0 , n-1 , l , r , 0);    }
    ll _getMax(int low , int high , int l, int r ,int i)
    {
        if(l > r)    return 0;   
        else if(l==low  && r == high)   return maxTree[i];  
        else
        {
            int mid = (low + high) >> 1;
            if(mid >= l && mid <= r)    return max(_getMax(low , mid , l , mid , 2*i+1),_getMax(mid+1 , high , mid+1 , r , 2*i+2)); 
            else if(r <= mid)           return _getMax(low , mid , l , r , 2*i+1);  
                return _getMax(mid + 1 , high , l , r , 2*i+2);
        }
    }
    ll query(int l,int r){  return getMax(l,r) - getMin(l,r);   }
};
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++)    cin>>arr[i];
    segTree s;  ll ans = 0; ll l =  0;
    for(ll r = 0;r<n;r++)
    {
        while(s.query(l,r) > k && l<=r)     l++;
        if(l<=r)    ans += (r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}