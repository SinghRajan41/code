#include<iostream>
#define ll long long int
using namespace std;
bool good(int m);
string str;
ll b,s,c;
ll nb,ns,nc,r;
ll pb,ps,pc;
bool good(ll m);
ll count(char key);
int main()
{
    cin>>str;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    ll low = 0;
    ll high = 1e14;
    ll mid,ans;
    b = count('B');
    s = count('S');
    c = count('C');
    while(low<=high)
    {
        mid = (low + high)>>1;
        if(good(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
ll count(char key)
{
    ll a = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == key)
            a++;
    }
    return a;
}
bool good(ll m)
{
    ll bred_need,sos_need,chis_need;
    ll cost = 0;
    bred_need = m*b;
    sos_need = m*s;
    chis_need = m*c;
    if(bred_need > nb)
        cost += (bred_need - nb)*pb;
    if(sos_need > ns)
        cost += (sos_need - ns) * ps;
    if(chis_need > nc)
        cost += (chis_need - nc) * pc;
    return cost <= r;
}