#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool seive[100001];
void init();
bool isPrime(ll n);
bool solve();
int gcd(int a,int b);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<( solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
bool solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    queue<pair<int,int>> q;
    int low,high,count;
    low = high = count = 0;
    while(high < n)
    {
        while((high + 1 < n) && arr[high + 1 ] == arr[high])    high++;
        q.push(make_pair(low,high));
        low = (++high);
    }
    while(!q.empty())
    {
        int l,r;
        l = q.front().first;
        r = q.front().second;
        q.pop();
        if((l== 0 || arr[l-1] > arr[l]) && (r==n-1 || arr[r+1] > arr[r])) count++;
        if(count >=2)
            return false;

    }
    return (count == 1 ? true : false);
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