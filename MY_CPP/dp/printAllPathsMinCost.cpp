/*1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
4. You are standing in top-left cell and are required to move to bottom-right cell.
5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-right cell).
7. You are required to traverse through the matrix and print the cost of the path which is least costly.
8. Also, you have to print all the paths with minimum cost.*/
#include<iostream>
#include<vector>
using namespace std;
void printPath(int r,int c,vector<vector<int>> &cost);
void dfs(int i,int j,int r,int c,vector<vector<pair<char,char>>> &path,string psf);
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> cost;
    for(int i=0;i<r;i++)
    {
        vector<int> temp(c);
        cost.push_back(temp);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>cost[i][j];
    }
    printPath(r,c,cost);
    return 0;
}
void dfs(int i,int j,int r,int c,vector<vector<pair<char,char>>> &path , string psf)
{
    if(i>r || j>c)
        return;
    if(i==r && j==c)
    {
        cout<<psf<<"\n";
    }
    else
    {
        if(path[i][j].first == 'H')
        {
            dfs(i,j+1,r,c,path,psf + 'H');
        }
        if(path[i][j].second == 'V')
        {
            dfs(i+1,j,r,c,path,psf + 'V');
        }
    }
}
void printPath(int r,int c,vector<vector<int>> &cost)
{
    vector<vector<int>> dp;
    vector<vector<pair<char,char>>> path;
    for(int i=0;i<r;i++)
    {
        vector<int> temp(c,-1);
        vector<pair<char,char>> temp2(c , {'*' ,  '*'});
        dp.push_back(temp);
        path.push_back(temp2);
    }
    dp[r-1][c-1] = cost[r-1][c-1];
    for(int i=r-1;i>=0;i--)
    {
        for(int j=c-1;j>=0;j--)
        {
            if(i==r-1 && j == c-1)
                continue;
            else 
            {
                int x = 1000000;
                if(i+1<r)
                    x = min(x , dp[i+1][j]);
                if(j+1<c)
                    x = min(x , dp[i][j+1]);
                dp[i][j] = x + cost[i][j];
                

                if(i+1<r && dp[i+1][j] == x)
                    path[i][j].second = 'V';
                if(j+1<c && dp[i][j+1] == x)
                    path[i][j].first = 'H';
            }

        }
    }
    cout<<dp[0][0]<<"\n";
    dfs(0,0,r-1,c-1,path , "");
    
}

