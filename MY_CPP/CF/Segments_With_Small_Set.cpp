/*
Given an array of n integers ai. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) 
is good if there are no more than k unique elements on this segment. Your task is to find the number of different good segments.
*/
#include<iostream>
using namespace std;
class map
{
    int *arr;   int n;  int sz;
    public:
    map()
    {
        n = 1e5+1;
        arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = 0;
        sz = 0;
    }
    void insert(int a)
    {
        arr[a]++;
        if(arr[a] == 1)
            sz++;
    }
    void remove(int a)
    {
        if(arr[a] == 0)
            return;
        else
        {
            arr[a]--;
            if(arr[a] == 0)
                sz--;
        }
    }
    int size()
    {
        return sz;
    }
};
int main()
{
    int n,k,*arr;
    cin>>n>>k;
    arr = new int[n];   for(int i=0;i<n;i++)    cin>>arr[i];
    unsigned long long int res = 0;
    int l = 0;
    map mp;
    for(int r= 0;r<n;r++)
    {
        mp.insert(arr[r]);
        while(mp.size()  >  k)
        {
            mp.remove(arr[l++]);
        }
        if(r>=l)
            res += (r-l+1);
    }
    cout<<res<<"\n";
    return 0;
}