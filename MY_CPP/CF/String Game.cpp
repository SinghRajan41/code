#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<cstdlib>
#define ll long long int
#define nl cout<<"\n"
using namespace std;
string p,t;
int order[int(2e5+1)];
int n,x;
bool f(int m);
int main()
{
    cin>>p;
    cin>>t;
    n = p.length();
    x = t.length();
    for(int i=0;i<n;i++)
        cin>>order[i];
    int low = 0;
    int high = n-1;
    int ans = 0;
    bool flag = false;
    while(low<=high)
    {
        int mid = (low + high)>>1;
        if(f(mid))
        {
            low = mid  + 1;
            ans = mid;
            flag = true;
        }
        else    
        {
            high = mid - 1;
        }
    }
    cout<<(flag ? ans+1 : 0)<<"\n";
    return 0;
}
bool f(int m)
{
    unordered_map<int,int> map;
    for(int i=m+1;i<n;i++)
        map[order[i]-1] = 1;
    int i,j;
    i = j = 0;
    while(j<x)
    {
        while(i<n && (map[i] == 0 || p[i] != t[j]))
        {
            i++;
            if(i==n)
                return false;
        }
        if(i==n)
            return false;
        else
        {
            i++;
            j++;
        }
    }
    return j==x ? true:false;
}

