/*
https://docs.google.com/document/d/1zuw8hBXHsiTYTH8u986fQhn8TWfpOk9BQBIRH3lo_W8/edit     //problem statement
*/
#include<iostream>
#include<vector>
using namespace std;
int min_cost(int i , int s , int n , vector<vector<int>> &cost , vector<vector<int>> &dp);
int main()
{
    int n;  cin>>n;
    vector<vector<int>> cost(n , vector<int>(n , -1));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    vector<vector<int>> dp(n , vector<int>(1<<(n+1) , -1));
    cout<<min_cost(0 , (1<<n) - 1 , n , cost , dp);
    return 0;
}
int min_cost(int i , int s , int n , vector<vector<int>> &cost , vector<vector<int>> &dp)
{
    if(i==n)
        return 0;
    else
    {
        if(dp[i][s] != -1)  return dp[i][s];
        int ans = 1e9;
        for(int j=0;j<n;j++)
        {
            //if the j'th bit is set in s, then assign ith person the work j
            if((1 << j) & (s))
            {
                int y = s;
                int mask = (~(1 << j));
                y = mask & y;
                int x = min_cost(i+1 , y , n,cost , dp) + cost[i][j];
                ans = min(ans , x); 
            }
        }
        return dp[i][s] = ans;
    }
}