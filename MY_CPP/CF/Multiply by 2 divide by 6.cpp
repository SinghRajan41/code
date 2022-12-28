#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
using namespace std;
bool isPrime[100001];
void init();
bool solve();
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
bool solve()
{
    int n;
    cin>>n;
    int two,three;
    two = three = 0;
    while(n>1 && n%2==0)
    {
        two++;
        n>>=1;
    }
    while(n>1 && n%3 == 0)
    {
        three++;
        n/=3;
    }
    if(two <=three && n==1)
    {
        cout<<(three - two + three)<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }
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
