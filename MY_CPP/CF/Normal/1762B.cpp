#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<set>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool *seive;
int *sp;
void init_seive();
void init_sp();
int solve();
ll binExp(ll a,ll b);
ll binExpM(ll a,ll b,ll M);
void printVector(vector<int> arr);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return  0;
}
int solve()
{
    ll n;
    vector<pair<ll,ll>> arr;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        arr.push_back(make_pair(x,i+1));
    }
    sort(arr.begin() , arr.end());
    bool ok = true;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first % arr[i-1].first != 0)
        {
            ok = false;
            break;
        }
    }
    if(ok)
    {
        cout<<"0\n";
        return 0;
    }
    else
    {
        ll m[n+1];
        for(int i=0;i<=n;i++)
            m[i] = 0;
        ll lcm;
        ll a = arr[0].first;
        lcm = a;
        for(int i=1;i<n;i++)
        {
            a = arr[i].first;
            a = lcm*((a + lcm -1)/lcm);
            m[arr[i].second] = a - arr[i].first;
            lcm = a;
        }
        cout<<n<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<i+1<<" "<<m[i+1]<<"\n";
        }
    }
    return 0;
}
void printVector(vector<int> arr)
{
    for(auto i:arr)
        cout<<i<<" ";
    nl;
}
void init_sp()
{
    sp = new int[10000001];
    int M = 10000001;
    for(int i=0;i<M;i++)
        sp[i] = -1;
    sp[1] = 1;
    for(int i=2;i<M;i+=2)
        sp[i] = 2;
    for(int i=3;i<M;i++)
    {
        if(sp[i] == -1)
        {
            sp[i] = i;
            for(int j=2*i;j<M;j+=i)
                if(sp[j] == -1)
                    sp[j] = i;
        }
    }
}
ll binExpM(ll a,ll b,ll M)
{
    if(b==0)
        return a;
    else
    {
        ll res = 1;
        while(b)
        {
            if(b&1)
                res = ((res%M) * (a%M))%M;
            a = (a*a)%M;
            b>>=1;
        }
        return res;
    }
}
ll binExp(ll a,ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll res = 1;
        while(b)
        {
            if(b & 1)
                res *= a;
            a *= a;
            b>>=1;
        }
        return res;
    }
}

void init_seive()
{
    seive = new bool[10000001];
    for(int i=0;i<100001;i++)   seive[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(seive[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                seive[j] = false;
            }
        }
    }
}