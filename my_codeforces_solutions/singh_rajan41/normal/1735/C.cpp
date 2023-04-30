#include<bits/stdc++.h>
using namespace std;
void solve();
unordered_map<char , char> parent;
char find(char a);
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
    int n;  cin>>n;
    string s;   cin>>s;
    vector<char> res;unordered_map<char , char> mapping;
    for(int i=0;i<26;i++)
    {
        res.push_back(('a' + i));parent[res[i]] = res[i] , mapping[res[i]] = '#';
    }
    for(int i=0;i<n && res.size() > 0;i++)
    {
        if(mapping[s[i]] == '#')
        {
            if(res.size() == 1)
            {
                mapping[s[i]] = res[0];
                res.erase(res.begin());
            }
            else
            {
                for(auto j = res.begin(); j != res.end() ; j++)
                {
                    char a = s[i];
                    char b = *j;
                    if(find(a)  != find(b))
                    {
                        parent[a] = b;
                        mapping[a] = b;
                        res.erase(j);
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<mapping[s[i]];
    cout<<"\n";
}
char find(char a)
{
    if(parent[a] == a)
    {
        return a;
    }
    else
    {
        return parent[a] = find(parent[a]);
    }
}