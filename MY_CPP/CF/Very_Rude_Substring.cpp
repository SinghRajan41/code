#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    ll n,limit,rude = 0,a = 0,b = 0,l = 0,r = 0,ans = 0;
    cin>>n>>limit;
    char s[n];
    for(int i=0;i<n;i++)    cin>>s[i];
    for(r=0;r<n;r++)
    {
        if(s[r] == 'b') {   rude += a;  b++;    }
        if(s[r] == 'a') a++;
        
        while(rude > limit)
        {
            if(s[l] == 'a') {   rude -= b;  a--;    }
            if(s[l] == 'b') b--;
            l++;
        }
        if(l<=r)    ans = max(ans , r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}