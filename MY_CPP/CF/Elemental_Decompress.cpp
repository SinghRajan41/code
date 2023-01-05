#include<iostream>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
void solve();
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
void solve()
{
    int n;  cin>>n; int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int p[n],q[n];
    for(int i=0;i<n;i++)    p[i] = q[i] = -1;
    unordered_map<int,int> p_map,q_map; set<int> p_s,q_s;
    for(int i=1;i<=n;i++){  p_s.insert(i);  q_s.insert(i);  }
    for(int i=0;i<n;i++)
    {
        if(!p_map[arr[i]]){ p_map[arr[i]]++;    p_s.erase(arr[i]);  p[i] = arr[i];  }
        else if(!q_map[arr[i]]){    q_map[arr[i]]++;    q_s.erase(arr[i]);  q[i] = arr[i];  }
        else{   cout<<"NO\n";return;    }
    }
    for(int i=0;i<n;i++)
    {
        if(p[i] == -1)
        {
            auto it = p_s.upper_bound(arr[i]);
            if(it == p_s.begin())   {   cout<<"NO\n";   return; }
            else    {--it;p[i] = *it;p_s.erase(*it);}
        }
        else
        {
            auto it = q_s.upper_bound(arr[i]);
            if(it == q_s.begin())   {   cout<<"NO\n";   return; }
            else    {   --it;  q[i] = *it; q_s.erase(*it);}
        }

    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)    cout<<p[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)    cout<<q[i]<< " ";
    cout<<"\n";
}

    /*for(auto i = q_s.begin() ; i != q_s.end() ; i++)
        cout<<(*i)<<" ";*/
    /*for(int i=0;i<n;i++)
        cout<<p[i]<< " ";
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<q[i]<<" ";
    cout<<"\n";*/