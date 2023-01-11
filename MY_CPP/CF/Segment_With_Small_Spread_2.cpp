#include<iostream>
#include<stack>
#define ll long long int
using namespace std;
ll n,k;
ll arr[(int)1e5+1];
class queue
{
    stack<ll> SL,SR,SL_Max,SL_Min,SR_Max,SR_Min;
    public:
    void enqueue(ll a); void dequeue(); ll spread();
};
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    cin>>n>>k;  for(int i=0;i<n;i++)    cin>>arr[i];
    ll l,r,ans; l = r = ans = 0;
    queue q;
    for(;r<n;r++)
    {
        q.enqueue(arr[r]);
        while(q.spread() > k)   {q.dequeue(); l++;}
        if(q.spread() <= k  && q.spread() != -1 && l<=r)    ans += (r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}
void queue::enqueue(ll a)
{
    if(SR.empty())  {   SR.push(a) ; SR_Max.push(a);    SR_Min.push(a); }
    else    {   SR.push(a); SR_Min.push(min(SR_Min.top() , a)); SR_Max.push(max(SR_Max.top() , a)); }
}
void queue::dequeue()
{
    bool l,r;   l = SL.empty(); r = SR.empty();
    if(l && r)  return;
    else if(l || r)
    {
        if(l)
        {
            while(!SR.empty())
            {
                ll a = SR.top();    SR.pop();   SR_Min.pop();   SR_Max.pop();
                if(SL.empty())  {   SL.push(a); SL_Min.push(a); SL_Max.push(a); }
                else    {   SL.push(a); SL_Min.push(min(a , SL_Min.top())); SL_Max.push(max(a , SL_Max.top()));    }
            }
        }
    }
    SL.pop();   SL_Min.pop();   SL_Max.pop();
}
ll queue::spread()
{
    bool l,r;   l = SL.empty(); r = SR.empty();
    if(l && r)  return -1;
    else if(l || r){    if(l)   return SR_Max.top() - SR_Min.top(); else    return SL_Max.top() - SL_Min.top(); }
    else    {   return max(SR_Max.top() , SL_Max.top())  - min(SL_Min.top() , SR_Min.top());    }
}