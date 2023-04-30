#include<bits/stdc++.h>
using namespace std;
string f(string &s1 , string &s2 , int i, int j,vector<vector<string>> &dp);
int main()
{
    string s1 = "raxjyazn";
    string s2 = "prqapjhatn";
    int n = s1.size();
    int m = s2.size();
    vector<vector<string>> dp(n , vector<string>(m , "$"));
    string lcs = f(s1 , s2 , n-1 , m-1 , dp);
    for(int i=0;i<lcs.length()/2;i++)
    {
        swap(lcs[i] , lcs[lcs.length()-1-i]);
    }
    int j = 0;
    int k = 0;
    string res = "";
    for(int i=0;i<lcs.length();i++)
    {
        while(j<n && s1[j] != lcs[i])
        {
            res.push_back(s1[j]);
            j++;
        }
        while(k<m && s2[k] != lcs[i])
        {
            res.push_back(s2[k]);
            k++;
        }
        res.push_back(lcs[i]);
        j++;
        k++;
    }
    while(j<n)
    {
        res.push_back(s1[j]);
        j++;
    }
    while(k<m)
    {
        res.push_back(s2[k]);
        k++;
    }
    cout<<res<<"\n";
    cout<<s1.length()<<" "<<s2.length()<<" "<<res.length()<<"\n";
    return 0;
}
string f(string &s1 , string &s2 , int i, int j ,  vector<vector<string>> &dp)
{
    if(i<0 || j<0)
        return "";
    else
    {
        if(dp[i][j] == "$")
        {
            if(s1[i] == s2[j])
                return dp[i][j] = s1[i] + f(s1 , s2 , i-1 , j-1 , dp);
            else
            {
                string a,b;
                a = f(s1 , s2 , i-1 , j , dp);
                b = f(s1 , s2 , i , j-1 , dp);
                if(a.length() > b.length())
                    return dp[i][j] = a;
                else
                    return dp[i][j] = b;
            }
        }
        else
        {
            return dp[i][j];
        }
    }
}