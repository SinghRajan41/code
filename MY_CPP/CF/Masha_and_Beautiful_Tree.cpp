#include<iostream>
using namespace std;
void solve();
int parent[(int)3e5];
int find(int a){
    if(parent[a] == a)
        return a;
    else
        return parent[a] = find(parent[a]);
}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t;  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
bool check(int arr[],int n)
{
    int a= 1,b;
    for(int i=1;i<=n;i++)   parent[i] = i;
    for(int j=2;j<=n;j*=2)
    {
        int l,r;
        l = r = 1;
        while(r<=n)
        {
            if(r-l == j)
            {
                l = r;
            }
            else
            {
                a = find(r);
                parent[a] = l;
            }
            r++;
        }
        l = r = 1;
        while(r <= n)
        {
            if(r-l == j)
            {
                l = r;
            }
            else
            {
                if((find(arr[l]) ^ find(arr[r])))
                    return false;
            }
            r++;
        }
        for(int i=1;i<=n;i++)   parent[i] = i;
    }
    return true;
}
void solve()
{
    int n;  cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    if(check(arr , n))
    {
        cout<<"OK\n";
    }
    else
    {
        cout<<"-1\n";
    }
}