#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count = 0;
    int mark = arr[k-1];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=mark && arr[i]!=0)
        {
            count++;
        }
    }
    cout<<count;
    return 0;
}