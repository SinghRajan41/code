#include <iostream>
#include<algorithm>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
int solve(int arr[],int n);
void google(int x);
ll ceildiv(ll a,ll b)
{
   return (a/b) + (a%b==0 ? 0:1);
}
int a[200001];
int n,chairs;
ll need;
int main()
{
   FIO
   int t;
   cin >> t;
   while(t--)
   {
      cin>>n>>chairs;
      for(int i=0;i<n;i++)
         cin>>a[i];
      need = 0;
      sort(a , a + n);
      for(int i=0;i<n;i++)
         need += (a[i] + 1);
      need += (a[n-1] - a[0]);
      cout<< (need <= chairs ? "YES\n" : "NO\n");
   }
   return 0;
}
void google(int x)
{
   cout<<"Case #"<<x<<": ";
}