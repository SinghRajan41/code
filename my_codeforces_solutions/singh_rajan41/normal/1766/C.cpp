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
    string s[2];
    cin>>s[0];
    cin>>s[1];
    int b[n];
    for(int i=0;i<n;i++)
        b[i] = 0;
    for(int i=0;i<n;i++)
    {
        int count = 0;
        if(s[0][i] == 'B')  count++;
        if(s[1][i] == 'B')  count++;
        b[i] = count;
        /*if(count == 0)
            return 0;*/
    }
    for(int i=0;i<n-1;i++)
    {
        if(b[i] == 1)
        {
            if((s[0][i]=='B' && s[0][i+1]=='B') || (s[1][i]=='B' && s[1][i+1]=='B'))
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    int low,high;
    low = high = 0;
    vector<pair<int,int>> seg;
    while(high<n)
    {
        if(b[high] == 2)
        {
            while((high + 1 < n) && b[high+1] == b[low])
                high++;
            seg.push_back(make_pair(low,high));
            high++;
            low = high;
        }
        else
        {
            high++;
            low++;
        }
    }
    for(auto st:seg)
    {
        low = st.first;
        high = st.second;
        if(high != n-1 && low != 0)
        {
            int size = high - low + 1;
            if(size & 1)
            {
                if((s[0][low-1]=='B' && s[1][high+1]=='B') || (s[1][low-1]=='B' && s[0][high+1]=='B'))
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if((s[0][low-1]=='B' && s[0][high+1]=='B') || (s[1][low-1]=='B' && s[1][high+1]=='B'))
                {
                    continue;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 1;
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