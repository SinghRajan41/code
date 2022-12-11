/*
Medium  Prev   Next
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add up to "tar" or not.
5. Also, you have to print the indices of elements that should be selected to achieve the given target.
6. You have to print all such configurations.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define ll unsigned long long int
using namespace std;
bool isPrime[100001];
void init();
bool solve();
ll binExp(ll a,ll b);
ll binExpM(ll a,ll b,ll M);
void printAllSubsets(int arr[],int n,int tar,vector<int> temp,int i);
void dfs(int i,int j,vector<vector<bool>> &dp,vector<int> path,int arr[]);
void printSubsets(int arr[],int n,int tar);
void printVector(vector<int> &arr);
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i+1];
    int tar;
    cin>>tar;
    printSubsets(arr,n,tar);
    return 0;
}
void dfs(int i,int j,vector<vector<bool>> &dp,vector<int> path,int arr[])
{
    if(i == 0)
    {
        if(j==0)
        {
            printVector(path);
        }
    }
    else
    {
        int key = arr[i];
        if(dp[i-1][j])
        {
            dfs(i-1,j,dp,path,arr);
        }
        if(j-key>=0 && dp[i-1][j-key])
        {
            path.push_back(i);
            dfs(i-1,j-key,dp,path,arr);
        }
    }
}
void printVector(vector<int> &arr)
{
    for(int i=arr.size()-1;i>=0;i--)
    {
        cout<<arr[i]-1<<" ";
    }
    cout<<"\n";
}
void printSubsets(int arr[] , int n,int tar)
{
    vector<vector<bool>> dp;
    for(int i=0;i<=n;i++)
    {
        vector<bool> temp(tar +1 , false);
        dp.push_back(temp);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=tar;j++)
            dp[i][j] = false;
    dp[0][0] = true;
    for(int i=1;i<=n;i++)
    {
        int key = arr[i];
        for(int j=0;j<=tar;j++)
        {
            dp[i][j] = dp[i][j] | dp[i-1][j];
            if(j-key >= 0)
            {
                dp[i][j] =  dp[i][j] | dp[i-1][j-key];
            }
        }
    }
    if(dp[n-1][tar])
    {
        cout<<"true\n";
    }
    else
    {
        cout<<"false\n";
        return;
    }
    vector<int> path;
    dfs(n,tar,dp,path,arr);
    // printAllSubsets(arr , n , tar , path , 1);

}
void printAllSubsets(int arr[],int n,int tar,vector<int> temp,int i)
{
    //Recursive solution
    //Time complexity O(2^n)
    if(i>n+1)
        return;
    else if(i==n+1)
    {
        int sum = 0;
        for(auto j:temp)
            sum += arr[j];
        if(sum == tar)
        {
            for(auto j:temp)
                cout<<j-1<<" ";
            cout<<endl;
        }
    }
    else
    {
        printAllSubsets(arr,n,tar,temp,i+1);
        temp.push_back(i);
        printAllSubsets(arr,n,tar,temp,i+1);
    }
}
ll binExpM(ll a,ll b,ll M)
{
    if(b==0)
        return a;
    else
    {
        ll res = 1;
        while(b)
        {
            if(b&1)
                res = ((res%M) * (a%M))%M;
            a = (a*a)%M;
            b>>=1;
        }
        return res;
    }
}
ll binExp(ll a,ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll res = 1;
        while(b)
        {
            if(b & 1)
                res *= a;
            a *= a;
            b>>=1;
        }
        return res;
    }
}
bool solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i+=2)
    {
        if((s[i] - '0')&1)
            return true;
    }
    return false;
}
void init()
{
    for(int i=0;i<100001;i++)   isPrime[i] = true;
    for(int i=2;i<100001;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<100001;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}