#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;

        vector<int> left,right;
        int size = n/2;
        left.push_back(a);
        right.push_back(b);
        vector<bool> vis(n,false);
        vis[a] = vis[b] = true;
        for(int i=1;i<=a-1;i++)
        {
            if(right.size() == size)
                break;
            else if(!vis[i])
                {right.push_back(i);vis[i] = true;}
        }   
        for(int i = b+1;i<=n;i++)
        {
            if(left.size() == size)
                break;
            else if(!vis[i])
                {left.push_back(i);vis[i] = true;}
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(left.size() != size)
                {
                    left.push_back(i);
                    vis[i] = true;
                    continue;
                }
                if(right.size() != size)
                {
                    right.push_back(i);
                    vis[i] = true;
                }
            }
        }

    if(left.size() == size && right.size() == size)
    {
        int mn = INT32_MAX;
        int mx = INT32_MIN;
            for(int i = 0;i<size;i++)
            {
                mn = min(mn , left[i]);
                mx = max(mx , right[i]);
            }
            if(mn == a && mx == b)
            {
                for(auto i:left)
                {
                    cout<<i<<" ";
                }
                for(auto i:right)
                {
                    cout<<i<<" ";
                }
                cout<<endl; 
            }
            else
            {
                cout<<"-1\n";
            }
        }
    else
    {
        cout<<"-1\n";
    }
        
    

}
int main()
{
    int t;
    cin>>t;
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    while(t--)
    {
        solve();
    }
    return 0;
}