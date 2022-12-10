#include<iostream>
#include<vector>
using namespace std;
#define ll unsigned long long int
vector<ll> trial_division(ll n);
int main()
{
    ll n;
    cin>>n;
    cout<<n<<endl;
    vector<ll> facs = trial_division(n);
    cout<<"1 ";
    for(auto i:facs)    cout<<i<<" ";
    cout<<endl;
    return 0;
}
vector<ll> trial_division(ll n)
{
    vector<ll> facs;
    while(!(n&1))
    {
        facs.push_back(2);
        n>>=1;
    }
    for(ll d=3 ; d*d<=n;d+=2)
    {
        while(!(n%d))
        {
            facs.push_back(d);
            n/=d;
        }
    }
    if(n>1)
    {
        facs.push_back(n);
    }
    return facs;
}