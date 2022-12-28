#include<algorithm>
#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void  solve();
void changeColor(char &col);
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
void changeColor(char &col)
{
    if(col == 'R')col = 'B';
    else col = 'R';
}
void solve()
{
    int n;
    cin>>n;
    char arr[n+1];
    for(int i =1;i<=n;i++)  cin>>arr[i];
    vector<pair<int,int>> seg;
    int low,high;
    low = high = 1;
    while(high<=n)
    {
        if(arr[high] == '?')
        {
            while(high<=n && arr[high] == '?')
            {
                high++;
            }
            seg.push_back(make_pair(low , high-1));
            low = high;
        }
        else
        {
            ++low;
            ++high;
        }
    }
    for(int i=0; i<seg.size() ; i++)
    {
        int low,high;
        low = seg[i].first;
        high = seg[i].second;
        char col;
        if(low-1>=1)
        {
            if(arr[low-1] == 'R')       col = 'B';
            else             col = 'R';
            for(int j = low;j<=high;j++)
            {
                arr[j] = col;
                changeColor(col);
            }
        }
        else if(high + 1 <=n)
        {
            if(arr[high+1] == 'R')      col = 'B';
            else                        col = 'R';
            for(int j = high;j>=low;j--)
            {
                arr[j] = col;
                changeColor(col);
            }
        }
        else
        {
            col = 'R';
            for(int j = low;j<=high;j++)
            {
                arr[j] = col;
                changeColor(col);
            }
        }

    }
    for(int i=1 ; i<=n ;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;

}
