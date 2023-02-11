#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
int solve(int arr[],int n);
void google(int x);
ll ceildiv(ll a,ll b)
{
   return (a/b) + (a%b==0 ? 0:1);
}
vector<int> arr(200001,0);
int n,chairs;
map<int,int> m;
ll need;
int main()
{
   FIO
   int t;
   cin >> t;
   for(;t--;)
   {
      ll n;
      cin>>n;
      cout<<ceildiv(n,2)<<endl;
   }
   return 0;
}
void google(int x)
{
   cout<<"Case #"<<x<<": ";
}