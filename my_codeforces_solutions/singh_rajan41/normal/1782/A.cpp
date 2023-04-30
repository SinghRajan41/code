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
int main()
{   ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
ll solve()
{
    int w,d,h,a,b,f,g;
    cin>>w>>d>>h>>a>>b>>f>>g;
    int arr[4];
    arr[0] = h + b + g + abs(a-f);
    arr[1] = h + d - b + d-g+abs(a-f);
    arr[2] = h + a + f + abs(g-b);
    arr[3] = h + w-a + w-f + abs(g-b);
    int ans = INT32_MAX;
    for(int i=0;i<4;i++)
        ans = min(ans , arr[i]);
    cout<<ans<<"\n";
    return 0;
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
vector<int> factorize(int n) {
    vector<int> facs;
    while(n > 1)
    {
        int f = sp[n];
        n/=f;
        facs.push_back(f);
    }
    return facs;

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