#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n;  cin>>n;
    vector<int> arr[n]; set<int> s;
    for(int i=0;i<n;i++)
    {
        int a;  cin>>a;
        for(int j=0;j<a;j++)    {   int x;  cin>>x;     arr[i].push_back(x);    s.insert(x);    }
        reverse(arr[i].begin() , arr[i].end());
    }
    set<int>::iterator it = s.begin();
    vector<int> d;
    for(;it != s.end();it++)    d.push_back((*it));
    reverse(d.begin() , d.end());   unordered_map<int,int> mp;
    for(int i=0;i<d.size();i++) {   mp[d[i]] = i;   }
    int sp = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i].size()-1;j++)
        {
            int idx = mp[arr[i][j]];
            int a = arr[i][j];
            int b = arr[i][j+1];
            if(a != b)
            {
                if(mp[a] + 1 != mp[b])
                {
                    sp++;
                }
            }
        }
    }
    cout<<sp<<" "<<sp + n-1<<"\n";
    return 0;

}