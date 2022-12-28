#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<map>
#include<unordered_map>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
bool seive[100001];
vector<int> primes;
vector<int> factorize(int n) ;
void init();
bool isPrime(ll n);
ll  solve();
int gcd(int a,int b);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
int aCount(string &s)
{
    int count = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'a')
            count++;
    }
    return count;
}
ll solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<string , int> m;
    for(int i=0;i<=n-2;i++)
    {
        string temp = s.substr(i,2);
        if(m[temp])
        {
            if(i-m[temp]>=1)
            {
                return 1;
            }
        }
        else
        {
            m[temp] = i+1;
        }
    }
    return 0;
}


vector<int> factorize(int n) {
    vector<int> factorization;
    for (int d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
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


