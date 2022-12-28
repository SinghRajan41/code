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
int binSearch(int arr[],int n,int key);
int closestToLeft(int arr[],int n,int key);
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<k;i++)
    {
        int q;
        cin>>q;
        cout<<closestToLeft(arr,n,q)<<"\n";
    }
    return 0;
}
int closestToLeft(int arr[],int n,int key)
{
    int low = 0;
    int high = n-1;
    int res = -1;
    while(low<=high)
    {
        int mid = (low + high)>>1;
        if(arr[mid] <= key)
        {
            low = mid  + 1;
            res = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res + 1;
}
int binSearch(int arr[],int n,int key)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low + high)>>1;
        if(arr[mid] == key)
            return 1;
        else
        {
            if(arr[mid] > key)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return 0;
}
ll solve()
{
    int x;
    cin>>x;
    map<int,int> m;
    for(int i=0;i<x;i++)
    {
        int n;
        cin>>n;
        vector<int> facs = factorize(n);
        unordered_map<int,int> check;
        for(auto j:facs)
        {
            if(check[j] == 0)
            {   m[j]++;
                check[j]++;
            }
        }
    }
    for(auto i = m.begin();i!=m.end();i++)
    {
        if((*i).second >=2 &&(*i).first != 1)
            return 1;
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