/*You are given two arrays a and b, sorted in non-decreasing order. Find the number of pairs (i,j) for which ai=bj.*/
// #include<iostream>
// #include<map>
// using namespace std;
// int main()
// {
//     int n,m;    cin>>n>>m;
//     map<int,int> mp;
//     for(int i=0;i<n;i++){int temp;cin>>temp;mp[temp]++;}
//     unsigned long long int ans = 0;
//     for(int i=0;i<m;i++)
//     {
//         int temp;   cin>>temp;
//         ans += mp[temp];
//     }
//     cout<<ans<<"\n";
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
//     int n,m;    cin>>n>>m;  int a[n],b[m];
//     for(int i=0;i<n;i++)    cin>>a[i];
//     for(int j=0;j<m;j++)    cin>>b[j];
//     int i=0;
//     unsigned long long int ans = 0;
//     for(int j=0;j<m;j++)
//     {
//         while(i<n && a[i] < b[j])   i++;
//         int k = i;
//         while(k<n && a[k]==b[j])    k++;
//         ans +=  (k-i);
//     }
//     cout<<ans<<"\n";
//     return 0;
// }
#include<iostream>
using namespace std;
int lowerBound(int arr[],int n,int key);
int upperBound(int arr[] , int n,int key);
int main()
{
    int n,m;    cin>>n>>m;  int a[n] , b[m];
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<m;i++)    cin>>b[i];
    unsigned long long int ans = 0;
    for(int i=0;i<m;i++)
    {
        ans += (-lowerBound(a, n , b[i]) + upperBound(a , n , b[i]));
    }
    cout<<ans<<"\n";
    return 0;
}
int lowerBound(int arr[],int n,int key)
{
    int res = n;int low = 0;int high = n-1;
    while(low <= high)
    {
        int mid = (low + high)>>1;
        if(arr[mid] >= key)
        {
            high = mid - 1;
            res = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
int upperBound(int arr[] , int n,int key)
{
    int res = n;int low = 0;int high = n-1;
    while(low <= high)
    {
        int mid = (low + high)>>1;
        if(arr[mid] <= key)
        {
            low = mid + 1;
            res = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}