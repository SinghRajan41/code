#include<iostream>
#include<stack>
#define ll long long int
using namespace std;
ll gcd(ll a, ll b)  {   return a==0 ? b : gcd(b%a , a); }
class queue
{
    stack<ll> SL,SR,SL_gcd,SR_gcd;
    public:
    void enqueue(ll a); void dequeue(); bool empty();   ll query();
};
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,l,r,ans = -1;
    cin>>n; l = r = 0;ll len = n;
    ll arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    queue q;
    
    for(l=0;l<n;l++)
    {
        while(q.query() != 1 && r<n)
        {   q.enqueue(arr[r++]);    }
        if(q.query() == 1){     len = min(len , r-l);ans = len;    }
        q.dequeue();
    }
    cout<<ans<<"\n";
    return 0;
}
bool queue::empty(){return SL.empty() && SR.empty();}
void queue::enqueue(ll a)
{
    if(SR.empty())
        SR.push(a) , SR_gcd.push(a);
    else
        SR.push(a) , SR_gcd.push(gcd(a , SR_gcd.top()));
}
void queue::dequeue()
{
    bool l,r;   l = SL.empty(); r = SR.empty();
    if(l && r)
        return;
    else if(l || r)
    {
        if(l)
        {
            while(!SR.empty())
            {
                if(SL.empty()){SL.push(SR.top());SL_gcd.push(SR.top());}
                else
                {
                    SL.push(SR.top());
                    SL_gcd.push(gcd(SR.top() , SL_gcd.top()));
                }
                SR.pop();   SR_gcd.pop();
            }
        }
    }
    SL.pop();   SL_gcd.pop();
}
ll queue::query()
{
    bool l,r;   l = SL.empty(); r = SR.empty();
    if(l && r)
        return -1;
    else if(l || r)
    {
        if(l)   return SR_gcd.top();
        else    return SL_gcd.top();
    }
    else
    {
        return gcd(SR_gcd.top() , SL_gcd.top());
    }
}