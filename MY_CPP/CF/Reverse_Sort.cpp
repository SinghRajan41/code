#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve();
int main()
{
    int t;  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n;  cin>>n;
    string s;
    cin>>s;
    bool not_sorted = false;
    for(int i=0;i<n-1;i++)
    {
        if(s[i] > s[i+1])
        {
            not_sorted = true;
            break;
        }
    }
    if(not_sorted)
    {
        string ss = s;
        sort(ss.begin() , ss.end());
        //cout<<s<<" "<<ss<<" ";
        cout<<"1\n";
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(s[i] ^ ss[i])
            {
                res.push_back(i+1);
            }
        }
        cout<<res.size()<< " ";
        for(auto i:res)
            cout<<i<<" ";
        cout<<"\n";
    }
    else
    {
        cout<<"0\n";
    }
}