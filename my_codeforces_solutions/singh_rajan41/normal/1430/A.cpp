#include<iostream>
#include<vector>
#include<queue>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
void solve();
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    if(n==1 || n==4 || n==2)
    {
        cout<<"-1\n";
        return;
    }
    else if(n%3 == 0)
    {
        cout<<n/3<<" 0 0\n";
    }
    else if(n%5 == 0)
    {
        cout<<"0 "<<n/5<<" 0\n";
    }
    else if(n%7 == 0)
    {
        cout<<"0 0 "<<n/7<<endl;
    }
    else
    {
        if(n%3 == 1)
        {
            cout<<(n-7)/3<<" 0 1\n";
        }
        else
        {
            cout<<(n-5)/3<<" 1 0\n";
        }
    }
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