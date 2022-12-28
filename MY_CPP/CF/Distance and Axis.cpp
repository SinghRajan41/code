#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
bool solve();
ll count(ll n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        if(solve() == false)
            cout<<"Not found\n";
    }
    return 0;
}
ll count(ll n)
{
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else
        return (n-1)*count(n-2) + count(n-1);
}
bool solve()
{
    int n,k;
    cin>>n>>k;
    if(n < k)
        cout << k - n << endl;

    else if(n % 2 == k % 2)
        cout << 0 << endl;

    else
        cout << 1 << endl;
    return true;
}
void init()
{
    for(int i=0;i<100001;i++)   isPrime[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}
