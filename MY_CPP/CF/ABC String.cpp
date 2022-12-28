#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#define ll long long int
using namespace std;
void  solve();
ll ceilDiv(ll a, ll b);
bool check(vector<char> &arr);
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
bool check(string &s, int n , int k)
{
    if(k==0)    return true;
    else if(k == (n/2) && n%2 == 0) return false;
    else
    {
        for(int i = 0;i<k;i++)
        {
            if(s[i] != s[n-i-1])    return false;
        }
        return true;
    }
}
bool check(vector<char> &arr)
{
    int x = 0;
    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i] == '(')
        {
            x++;
        }
        else
        {
            if(x == 0)return false;
            else    x-=1;
        }
    }
    return x==0 ? true:false;
}
void solve()
{
    string s;
    cin>>s;
    int n = s.length();
    vector<string> keys;
    keys.push_back("001");
    keys.push_back("010");
    keys.push_back("011");
    keys.push_back("100");
    keys.push_back("101");
    keys.push_back("110");
    vector<char> res(n);
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j<s.length();j++)
        {
            string key = keys[i];
            if(s[j] == 'A')
            {
                res[j] = key[0]=='1' ? '(' : ')';
            }
            else if(s[j] == 'B')
            {
                res[j] = key[1]=='1' ? '(' : ')';
            }
            else if(s[j] == 'C')
            {
                res[j] = key[2]=='1' ? '(' : ')';
            }
        }
        if(check(res))
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
ll ceilDiv(ll a , ll b)
{
    return (a/b + (a%b == 0 ? 0 : 1));
}