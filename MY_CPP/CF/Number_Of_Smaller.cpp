/*You are given two arrays, sorted in non-decreasing order. 
For each element of the second array, find the number of elements in the first array strictly less than it.*/
#include<iostream>
using namespace std;
int main()
{
    int n,m;    cin>>n>>m;  int a[n],b[m];
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];
    int p = 0;
    for(int i=0;i<m;i++)
    {
        while(p<n && a[p] < b[i])   p++;
        cout<<p<<" ";
    }
    return 0;
}