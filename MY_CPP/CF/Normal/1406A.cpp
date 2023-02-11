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
        solve();
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
    int n;
    cin>>n;
    int arr[n];
    int freq[101];
    for(int i=0;i<=100;i++) freq[i] = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]+=1;
    }
    int a,b;
    a = b = 0;
    for(int i=0;i<=100 && freq[i] > 0; i++)
    {
        if(freq[i] == 1)
        {
            if(a==i)
            {
                a++;
                continue;
            }
            if(b==i)
            {
                b++;
                continue;
            }
        }
        else
        {
            if(a == i)
            {
                a++;
            }
            if(b==i)
            {
                b++;
            }
        }
    }
    cout<<(a+b)<<"\n";
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