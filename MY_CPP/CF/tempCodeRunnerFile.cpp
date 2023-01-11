/*
Given an array of n integers ai. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) 
is good if there are no more than k unique elements on this segment. Your task is to find the number of different good segments.
*/
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,k,*arr;
    cin>>n>>k;
    arr = new int[n];   for(int i=0;i<n;i++)    cin>>arr[i];
    unsigned long long int res = 0;
    int l = 0;
    unordered_map<int,int> mp;
    for(int r= 0;r<n;r++)
    {
        mp[arr[r]]++;
        while(mp.size() > k)
        {   
            cout<<mp.size()<<"\n";
            if(mp.find(arr[l]) != mp.end())
            {
                mp[arr[l]] = mp[arr[l]] - 1;
            }
            l++;
        }
        if(l<=r)
            res += (r-l+1);
    }
    cout<<res<<"\n";
    return 0;
}