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
    int start = 4*(n-1) + 1;
    while((start<100001 && (!isPrime[start]))  || (isPrime[start - 4*(n-1)]))
        ++start;
    int dg = start - 4*(n-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == j)
            {
                cout<<dg<<" ";
            }
            else
            {
                cout<<"4 ";
            }
        }
        cout<<"\n";
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