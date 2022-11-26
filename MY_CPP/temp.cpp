#include <iostream>
#include<vector>
#define ll long long int
using namespace std;
void solve();
ll min(ll a,ll b,ll c)
{
	return min(min(a,b) , c);
}
ll max(ll a , ll b, ll c)
{
	return max(max(a,b) , c);
}
int gcd(int a,int b){return a==0 ? b : gcd(b%a,a);}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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
	int n,x;
	cin>>n>>x;
	int arr[n+1];
	bool mark[n+1];
	for(int i = 0;i<=n;i++)
	{
		mark[i] = false;
		arr[i] = -1;
	}
	arr[1] = x;
	arr[n] = 1;
	mark[1] = mark[x] = true;
	bool flag = false;
	for(int i=2 ; i<n ; i++)
	{
		for(int j = i; j<=n; j+=i)
		{
			if(mark[j] == false && i == j)
			{
				mark[j] = true;
				arr[i] = j;
				break;
			}
			else if(mark[j] == false && (n%j)==0)
			{
				mark[j] = false;
				arr[i] = j;
				break;
			}
		}
		if(arr[i] == -1)
		{
			flag = true;
			break;
		}
	}
	if(flag)
	{
		cout<<"-1\n";
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

/*#include<bits/stdc++.h>
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
}*/