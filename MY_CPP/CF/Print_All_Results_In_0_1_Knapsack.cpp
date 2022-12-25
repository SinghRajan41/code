/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without overflowing it's capacity.
5. Also, you have to print the indices of items that should be selected to make maximum profit.
6. You have to print all such configurations.

Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item again and again.
*/
#include<bits/stdc++.h>
using namespace std;
void printAllResult(int n,int limit,vector<int> price , vector<int> weight);
void dfs(int i,int j,vector<int> &weight,vector<int> &price , vector<vector<int>> &dp , vector<int> path);
void printVector(vector<int> &path);
int main()
{
    int n;
    cin>>n;
    vector<int> price(n+1) , weight(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>price[i+1];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i+1];
    }
    int limit;
    cin>>limit;
    printAllResult(n,limit,price,weight);
    return 0;
}
void printVector(vector<int> &path)
{
    for(int i=path.size()-1;i>=0;i--)
    {
        cout<<path[i]-1<<" ";
    }
    cout<<"\n";
}
void dfs(int i,int j,vector<int> &weight,vector<int> &price , vector<vector<int>> &dp , vector<int> path)
{
    if(i==0)
    {
        
            printVector(path);
        
    }
    else
    {
        int x = dp[i][j];
        if(x == dp[i-1][j])
        {
            dfs(i-1,j,weight,price,dp,path);
        }
        else if(j-weight[i]>=0 &&  (x  == price[i] + dp[i-1][j-weight[i]]))
        {
            path.push_back(i);
            dfs(i-1,j-weight[i],weight,price,dp,path);
        }
    }
}
void printAllResult(int n,int limit,vector<int> price , vector<int> weight)
{
    vector<vector<int>> dp;
    for(int i=0;i<=n;i++)
    {
        vector<int> temp(limit+1,0);
        dp.push_back(temp);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=limit;j++)
        {
            if(j-weight[i] >=0)
            {
                dp[i][j] = max(price[i] + dp[i-1][j-weight[i]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> path;
    cout<<dp[n][limit]<<"\n";
    dfs(n,limit , weight,price , dp , path);
}