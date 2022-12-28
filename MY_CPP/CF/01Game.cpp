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
    string s;
    cin>>s;
    int z,o;
    z = o = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '0') z++;
        else    o++;
    }
    cout<<((min(z,o) & 1) ? "DA\n" :"NET\n");
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
