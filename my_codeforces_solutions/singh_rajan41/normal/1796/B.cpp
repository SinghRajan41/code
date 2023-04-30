#include<bits/stdc++.h>
using namespace std;
void solve();
int f(string &s1 , string &s2 , int i1,int i2);
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  
    int t = 1;  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
int f(string &s1 , string &s2 , int i1,int i2)
{
    int len = 0;
    int n1 = s1.length();   int n2 = s2.length();
    while(i1 < n1 && i2 < n2 && s1[i1]==s2[i2])
    {
        len++;
        i1++;
        i2++;
    }
    return len;
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int max_len = 0;
    int i1,i2;  i1 = i2 = 0;
    int n1 = s1.length();   int n2 = s2.length();
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            int x = f(s1,s2,i,j);
            if(x > max_len)
            {
                max_len = x;
                i1 = i;
                i2 = j;
            }
        }
    }
    if(max_len >=2)
    {
        string ans = "*";
        ans.append(s1.substr(i1 , max_len));
        ans.push_back('*');
        cout<<"YES\n";
        cout<<ans<<"\n";
    }
    else if(max_len == 0)
    {
        cout<<"NO\n";
    }
    else
    {
        if(s1.back() == s2.back())
        {
            cout<<"YES\n";
            cout<<"*"<<s1.back()<<"\n";
        }
        else if(s1.front() == s2.front())
        {
            cout<<"YES\n";
            cout<<s1.front()<<"*\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}