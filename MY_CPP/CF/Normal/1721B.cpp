#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll long long int
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
        cout<<(solve())<<"\n";
    }
    return 0;
}
int solve()
{
    // int r,c,x,y,d;
    // cin>>r>>c>>x>>y>>d;
    // bool c1,c2;
    // c1 = c2 = true;
    // for(int i=1;i<=c;i++)
    //     if((abs(1-x) + abs(i-y)) <= d)  c1 = false;   
    // for(int i=1;i<=r;i++)
    //     if((abs(i-x) + abs(c-y)) <= d)  c2 = false;            //(abs(i-x) + abs(c-y)) <= d
    // if(c1 && c2)
    //     return r+c-2;
    // c1 = c2 = true;
    // for(int i=1;i<=c;i++)
    //     if((abs(r-x) + abs(i-y)) <= d)  c1 = false;             //(abs(r-x) + abs(i-y)) <= d
    // for(int i=1;i<=r;i++)
    //     if((abs(i-x) + abs(1-y)) <= d)  c2 = false;
    // return ((c1 && c2) ?  (r+c-2) : -1);        //(abs(i-x) + abs(1-y)) <= d
    // return -1;

    int r,c,x,y,d;
    cin>>r>>c>>x>>y>>d;
    // bool arr[r+1][c+1];
    /*for(int i=1;i<=r;i++)
    {   for(int j=1;j<=c;j++)   
        {
            if((abs(i-x) + abs(j-y)) <= d)
                arr[i][j] = false;
            else
                arr[i][j] = true;
        }
    }*/
    bool c1,c2;
    c1 = c2 = true;
    for(int i=1;i<=c;i++)
        if((abs(1-x) + abs(i-y)) <= d)  c1 = false;      ///(abs(1-x) + abs(i-y)) <= d
    for(int i=1;i<=r;i++)
        if((abs(i-x) + abs(c-y)) <= d)  c2 = false;      // (abs(i-x) + abs(c-y)) <= d
    if(c1 && c2)
        return r+c-2;
    c1 = c2 = true;
    for(int i=1;i<=c;i++)
        if((abs(r-x) + abs(i-y)) <= d)  c1 = false;       //  (abs(r-x) + abs(i-y)) <= d
    for(int i=1;i<=r;i++)
        if((abs(i-x) + abs(1-y)) <= d)  c2 = false;       // (abs(i-x) + abs(1-y)) <= d
    return ((c1 && c2) ?  (r+c-2) : -1);
    return -1;
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