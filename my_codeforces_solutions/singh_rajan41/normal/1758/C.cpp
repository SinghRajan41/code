#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, n, i, j, x, f;
	cin>>t;
    for(;t--;)
    {
        cin>>n>>x;
        f=0;
        bool mark[n+1];
        ll a[n+1];
        for(i=0; i<=n; i++)
        {
            mark[i]=false;
            a[i]=-1;
        }
        a[1]=x;
        a[n]=1;
        mark[1]=true;
        mark[x]=true;
        for(i=2; i<n; i++)
        {
            for(j=i; j<=n; j+=i){
                if(mark[j]==false && i==j)
                {
                    a[i]=j;
                    mark[j]=true;
                    break;
                }else if(mark[j]==false && (n%j)==0){
                    a[i]=j;
                    mark[j]=true;
                    break;
                }
            }
            if(a[i]==-1){
                f++;
                break;
            }
        }
        if(f>0){
            cout<<"-1\n";
            continue;
        }
        for(i=1; i<=n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}