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
bool *seive;
int *sp;
void init_seive();
const ll M = 998244353 ;
void init_sp();
ll solve();
ll binExp(ll a,ll b);
ll binExpM(ll a,ll b,ll M);
void printVector(vector<int> arr);
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return  0;
}
ll solve()
{
    int n;
    cin>>n;
    if(n==2)
    {
        cout<<"! 1 2\n";
        int x;
        cin>>x;
        if(x == -1)
        {
            exit(0);
        }
    }
    else
    {
        int a,b,c,x,y,nt;
        a = 1;
        b = 2;
        c = 3;
        nt = 4;
        for(int i=0;i<n-2;i++)
        {
            cout<<"? "<<a<<" "<<b<<"\n";
            cin>>x;
            cout<<"? "<<a<<" "<<c<<"\n";
            cin>>y;
            if(x == y)
            {   
                a = nt++;
            }
            else if(x < y)
            {
                b = nt++;
            }
            else if(x>y)
            {
                c = nt++;
            }
        }
        if(a == nt-1)
        {
            cout<<"! "<<b<<" "<<c<<"\n";
        }
        else if(b == nt-1)
        {
            cout<<"! "<<a<< " "<<c<<"\n";
        }
        else if(c == nt-1)
        {
            cout<<"! "<<a<<" "<<b<<"\n";
        }
        cin>>x;
        if(x == -1)
        {
            exit(0);
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
        return 1;
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
