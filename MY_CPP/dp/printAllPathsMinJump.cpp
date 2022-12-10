/*
1. You are given a number N representing number of elements.
2. You are given N space separated numbers (ELE : elements).
3. Your task is to find & print  
    3.1) "MINIMUM JUMPS" need from 0th step to (n-1)th step.
    3.2) all configurations of "MINIMUM JUMPS".
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[100001];
void init();
bool isPrime(ll n);
int  solve();
int gcd(int a,int b);
void dfs(int src,int dest,vector<int> adj[],vector<int> path);
void printPath(vector<int> path);
int main()
{
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void printPath(vector<int> path)
{
    for(int i=0;i<path.size();i++)
    {
        cout<<(path[i])<<(i != path.size() -1 ? " -> " : " .");
    }
    nl;
}
void dfs(int src,int dest,vector<int> adj[] , vector<int> path)
{
    if(src>dest)
        return;
    if(src == dest)
    {
        path.push_back(src);
        printPath(path);
        return;
    }
    else
    {
        path.push_back(src);
        for(int i=0 ; i<adj[src].size()  ; i++)
        {
            dfs(  adj[src][i] , dest , adj , path  );
        }
    }
}
int solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int dp[n];
    for(int i=0;i<n;i++)    dp[i] = -1;
    dp[n-1] = 0;
    vector<int> adj[n];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] == 0)
            dp[i] = -1;
        else
        {
            int x = 1000000;
            for(int j=1;j<=arr[i];j++)
            {   
                if((i+j < n) &&  (dp[i+j] != -1))
                {
                    x = min(x , dp[i+j]);
                }
            }
            dp[i] = x+1;
            for(int j=1;j<=arr[i];j++)
            {
                if((i+j<n) && (dp[i+j] != -1) && (dp[i+j] == x))
                {
                    adj[i].push_back(i+j);
                }
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     nl;
    // }
    cout<<dp[0]<<"\n";
    vector<int> path;
    dfs(0,n-1,adj , path);
    return 0;
}
int gcd(int a,int b)
{
    if(a == 0)
        return b;
    else
    {
        return gcd(b%a , a);
    }
}
bool isPrime(ll n)
{
    if((!(n&1)) && n!=2)
        return false;
    else
    {
        for(int i=3;i*i<=n;i+=2)
            if(n%i==0)  return false;
    }
    return true;
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


