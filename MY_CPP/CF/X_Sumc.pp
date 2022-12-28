#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[100001];
void init();
bool isPrime(ll n);
int  solve();
int gcd(int a,int b);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}
int solve()
{
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int x,y,sum;
            sum = 0;
            x = i;
            y = j;
            while(x>=0 && y>=0)
            {
                sum += arr[x--][y--];
            }
            x = i;
            y = j;
            while(x<r && y<c)
            {
                sum += arr[x++][y++];
            }
            x = i;
            y = j;
            while(x>=0 && y<c)
            {
                sum += arr[x--][y++];
            }
            x = i;
            y = j;
            while(x<r && y>=0)
            {
                sum += arr[x++][y--];
            }
            ans = max(ans,sum - 3*arr[i][j]);

        }
    }
    return ans;
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


