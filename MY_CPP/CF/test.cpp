#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool seive[10000001];
int sp[10000001];
vector<int> factorize(int n) ;
void init();            
void initsp();             
ll  solve();
int gcd(int a,int b);
ll mul(ll a,ll b);
int main()
{   
    init();
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        cout<<(solve())<<"\n";
    }
    return 0;
}

ll solve()
{
    int n,m,d;
    cin>>n>>m>>d;
    int arr[n+1];
    for(int i=1;i<=n;i++)   cin>>arr[i];
    int a[m];
    for(int i=0;i<m;i++)
        cin>>a[i];
    int pos[n+1];
    for(int i=1;i<=n;i++)
        pos[arr[i]] = i;
    for(int i=0;i<m-1;i++)
    {
        if(!((pos[a[i]] < pos[a[i+1]]) && (pos[a[i+1]] <= (d + pos[a[i]]))  ))
            return 0;
    }
    int ans = INT32_MAX;
    for(int i=0;i<m-1;i++)
    {
        int l = pos[a[i]];
        int r = pos[a[i+1]];
        if((l<r && (r <= (l+d))))
        {
            // try to push r beyond l + d 
            if(((l+d+1) <=n))
            {
                int cost = l + d + 1 - r;
                if(cost > 0)
                {
                    ans = min(ans , cost);
                }
            }
            //try to push r before l
            int x = r-l;
            ans = min(x , ans);
            if(d+2 <= n)
            {
                ans = min(ans , d+1-x);
            }
            
        }
    }
    return ans;
}
void initsp()
{
    int M = 10000001;
    for(int i=0;i<M;i++)
        sp[i] = -1;
    for(int i=2;i<M;i+=2)
        sp[i] = 2;
    sp[1] = 1;
    for(int i=3;i<M;i+=2)
    {
        if(sp[i]  == -1)
        {
            sp[i] = i;
            for(int j=2*i;j<M;j+=i)
            {
                if(sp[j] == -1)
                {
                    sp[j] = i;
                }
            }
        }
    }
}
int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
vector<int> factorize(int n)
{
    vector<int> f;
    while (!(n % 2)) 
    {
        n >>= 1; 
        f.push_back(2);
    }
    for (long long i = 3; i <= sqrt(n); i += 2) 
    {
        while (n % i == 0) 
        {
            f.push_back(i);
            n/=i;
        }
    }
    if(n>1)
        f.push_back(n);
    return f;
}

void init()
{
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




