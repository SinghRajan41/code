/*
Recall that a permutation of length n is an array where each element from 1 to n occurs exactly once.
For a fixed positive integer d, let's define the cost of the permutation p of length n as the number of indices i (1≤i<n) such that pi⋅d=pi+1.
For example, if d=3 and p=[5,2,6,7,1,3,4], then the cost of such a permutation is 2, because p2⋅3=p3 and p5⋅3=p6.
Your task is the following one: for a given value n, find the permutation of length n and the value d with maximum 
possible cost (over all ways to choose the permutation and d). If there are multiple answers, then print any of them.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[10000001];
int sp[10000001];
vector<int> factorize(int n) ;
void init();                // Initialises seive
void initsp();             // Initialises smallest prime array
int find(int n);
ll  solve();
int gcd(int a,int b);
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
ll solve()
{
    int n;
    cin>>n;
    bool mark[n+1];     for(int i=0;i<=n;i++)   mark[i] = false;
    int a = 1;
    cout<<"2\n";
    for(int i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            for(int j=i;j<=n;j*=2)
            {
                if(!mark[j])    {   cout<<j<<" ";   mark[j] = true; }
            }
        }
    }
    cout<<"\n";
    return 1;
}
void initsp()
{
    //Lookup table for finding the smallest prime factor of a number
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
    // Make sure that sp array is initialised
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
