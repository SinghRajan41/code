#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll unsigned long long int
#define nl cout<<"\n"
using namespace std;
bool *seive;
int *sp;
void init_seive();
void init_sp();
bool solve();
ll binExp(ll a,ll b);
ll binExpM(ll a,ll b,ll M);
void printVector(vector<int> arr);
vector<int> modify(vector<int> arr)
{
    vector<int> res;
    for(int i=0;i<arr.size();i+=2)
        res.push_back(arr[i]);
    for(int i=1;i<arr.size();i+=2)
        res.push_back(arr[i]);
    return res;
}
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
bool solve()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"YES\n";
        int count = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cout<<count++<<" ";
            }
            nl;
        }
    }
    else
    {
        if(n&1)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            vector<int> odds;
            vector<int> evens;
            for(int i=1,j=2;i<=n*k || j<=n*k;i+=2,j+=2)
            {
                if(i<=n*k)
                    odds.push_back(i);
                if(j<=n*k)
                    evens.push_back(j);
            }
            vector<int> res;
            for(auto i:odds)
                    res.push_back(i);
            for(auto i:evens)
                    res.push_back(i); 
            

            int idx = 0;
            //printVector(res);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<k;j++)
                    cout<<res[idx++]<<" ";
                cout<<"\n";
            }
        }
    }
    return false;
}
void printVector(vector<int> arr)
{
    for(auto i:arr)
        cout<<i<<" ";
    nl;
}
void init_sp()
{
    //Lookup table for smallest prime
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