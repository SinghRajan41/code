#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define nl cout<<"\n";
using namespace std;
void printAllPaths(int r,int c,vector<vector<int>> &gold);
bool valid(int i,int j,int r,int c);
struct node
{
    int x;
    int y;
    string psf;
    node *next;
    node()
    {
        x = y = -1;
        psf = "";
    }
};
class queue
{
    node *first,*last;
    public:
    queue()
    {
        first = last = NULL;
    }
    void insert(int x,int y,string psf)
    {
        node *temp = new node;
        temp->x = x;
        temp->y = y;
        temp->psf = psf;
        temp->next = NULL;
        if(first == NULL)
        {
            first = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    bool empty()
    {
        return first == NULL ? true:false;
    }
    node remove()
    {
        node temp;
        temp.x = first->x;
        temp.y = first->y;
        temp.psf = first->psf;
        node *x = first;
        if(first->next == NULL)
        {
            delete first;
            first = last = NULL;
        }
        else
        {
            first = first->next;
            delete x;
        }
        return temp;
    }
};
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> gold;
    for(int i=0;i<r;i++)
    {
        vector<int> temp(c,-1);
        gold.push_back(temp);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>gold[i][j];
    }
    printAllPaths(r,c,gold);
    return 0;
}
bool valid(int i,int j,int r,int c)
{
    return (i>=0 && i<r && j>=0 && j<c);
}
void printAllPaths(int r,int c,vector<vector<int>> &gold)
{
    vector<vector<int>> dp;
    for(int i=0;i<r;i++)
    {
        vector<int> temp(c,0);
        dp.push_back(temp);
    }
    for(int i=0;i<r;i++)
        dp[i][c-1] = gold[i][c-1];
    for(int j=c-2;j>=0;j--)
    {
        for(int i=0;i<r;i++)
        {
            int x = 0;
            if(valid(i+1,j+1,r,c))
            {
                x = max(x,dp[i+1][j+1]);
            }
            if(valid(i,j+1,r,c))
            {
                x = max(x,dp[i][j+1]);
            }
            if(valid(i-1,j+1,r,c))
            {
                x = max(x , dp[i-1][j+1]);
            }
            dp[i][j] =  x + gold[i][j];
        }
    }
    queue q;
    int x = 0;
    for(int i=0;i<r;i++)
        x = max(x , dp[i][0]);
    for(int i=0;i<r;i++)
    {
        if(dp[i][0] == x)
        {
            q.insert(i,0,to_string(i));
        }
    }
    cout<<x<<"\n";
    int i,j;
    vector<string> res;
    while(!q.empty())
    {
        node cur = q.remove();
        i = cur.x;
        j = cur.y;
        if(j == c-1)
        {
            res.push_back(cur.psf);
            continue;
        }
        x = dp[i][j] - gold[i][j];
        if(valid(i+1,j+1,r,c) && dp[i+1][j+1] == x)
        {
            q.insert(i+1,j+1,cur.psf + 'c');
        }
        if(valid(i,j+1,r,c) && dp[i][j+1] == x)
        {
            q.insert(i,j+1,cur.psf + 'b');
        }
        if(valid(i-1,j+1,r,c) && dp[i-1][j+1] == x)
        {
            q.insert(i-1,j+1,cur.psf + 'a');
        }
    }
    sort(res.begin() , res.end());
    for(auto psf:res)
    {
        for(auto i:psf)
        {
            if(i == 'a')
            {
                cout<<" d1";
                continue;
            }
            if(i == 'b')
            {
                cout<<" d2";
                continue;
            }
            if(i == 'c')
            {
                cout<<" d3";
                continue;
            }
            cout<<i;
        }
        cout<<" ";
        cout<<endl;
    }
}