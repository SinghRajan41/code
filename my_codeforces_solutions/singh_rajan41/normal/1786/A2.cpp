#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
using namespace std;
void solve();
ll add_mod_m(ll a, ll b,ll m);
ll sub_mod_m(ll a,ll b,ll m);
ll mul_mod_m(ll a,ll b,ll m);
ll div_mod_m(ll a,ll b,ll m);
ll extended_euclid(ll a,ll b, ll *x,ll * y);
ll binExp_Mod_M(ll a,ll b,ll m);
ll MMI(ll a,ll m);
ll gcd(ll a,ll b);
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n;
    int i=1;
    cin>>n;
    int aw,ab,bw,bb;
    aw = 1;
    ab = bw = bb = 0;
    n--;
    int l = 1;
    i++;
    bool f = true;
    while(n)
    {
        if(f)
        {
            //bob's turn
            if(n-i >=0)
            {
                if((l+1)%2==0)
                {
                    bb+= (i+1)/2;
                    bw += (i - (i+1)/2);
                }
                else
                {
                    bw += (i+1)/2;
                    bb += (i - (i+1)/2);
                }
                l+=i;n-=i;
            }
            else
            {
                if((l+1)%2==0)
                {
                    bb += (n+1)/2;
                    bw += (n - (n+1)/2);
                }
                else
                {
                    bw += (n+1)/2;
                    bb += (n - (n+1)/2);                    
                }
                l+=n;
                n=0;
                break;
            }
            i++;
            if(n-i >=0)
            {
                if((l+1)%2==0)
                {
                    bb+= (i+1)/2;
                    bw += (i - (i+1)/2);
                }
                else
                {
                    bw += (i+1)/2;
                    bb += (i - (i+1)/2);
                }
                l+=i;n-=i;
            }
            else
            {
                if((l+1)%2==0)
                {
                    bb += (n+1)/2;
                    bw += (n - (n+1)/2);
                }
                else
                {
                    bw += (n+1)/2;
                    bb += (n - (n+1)/2);                    
                }
                l+=n;
                n=0;
                break;
            }
            i++;
        }
        else
        {
            if(n-i>=0)
            {
                n-=i;
                if((l+1)%2==0)
                {
                    ab+= (i+1)/2;
                    aw += (i - (i+1)/2);
                }
                else
                {
                    aw += (i+1)/2;
                    ab += (i - (i+1)/2);
                }
                l+=i;
            }
            else
            {
                if((l+1)%2==0)
                {
                    ab += (n+1)/2;
                    aw += (n - (n+1)/2);
                }
                else
                {
                    aw += (n+1)/2;
                    ab += (n - (n+1)/2);                    
                }
                l+=n;
                n=0;
                break;
            }
            i++;
            if(n-i>=0)
            {
                n-=i;
                if((l+1)%2==0)
                {
                    ab+= (i+1)/2;
                    aw += (i - (i+1)/2);
                }
                else
                {
                    aw += (i+1)/2;
                    ab += (i - (i+1)/2);
                }
                l+=i;
            
            }
            else
            {
                if((l+1)%2==0)
                {
                    ab += (n+1)/2;
                    aw += (n - (n+1)/2);
                }
                else
                {
                    aw += (n+1)/2;
                    ab += (n - (n+1)/2);                    
                }
                l+=n;  
                n=0;
                break;
            }
            i++;
        }
        f = f ? false : true;
    }
    cout<<aw<< " "<<ab<<" "<<bw<<" "<<bb<<"\n";
}
ll add_mod_m(ll a, ll b,ll m)
{
    return ((a%m) + (b%m))%m;
}
ll sub_mod_m(ll a,ll b,ll m)
{
    return ((a%m) - (b%m) + m)%m;
}
ll mul_mod_m(ll a,ll b,ll m)
{
    return ((a%m) * (b%m))%m;
}
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
    {
        return gcd(b , a%b);
    }
}
ll extended_euclid(ll a,ll b, ll *x,ll * y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    else
    {
        ll g = extended_euclid(b , a%b , x,y);
        ll x1 = *x;
        ll y1 = *y;
        *x = y1;
        *y = x1 - y1*(a/b);
        return g;
    }
}
ll MMI(ll a,ll m)
{
    //return MODULAR INVERSE
    ll x,y;
    extended_euclid(a,m,&x,&y);
    x = ((x%m) + m)%m; // coz x may become negative
    return x;
}
ll binExp_Mod_M(ll a,ll b,ll m)
{
    ll x = a;
    ll res = 1;
    while(b > 0)
    {
        if(b&1)
        {
            res = ((res%m)*(x%m))%m;
        }
        b>>=1;
        x = ((x%m) * (x%m))%m;
    }
    return res;
}