#include<iostream>
#include<vector>
using namespace std;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n;  cin>>n;
    vector<int> odd,even;
    for(int i=0;i<n;i++)
    {
        int temp;   cin>>temp;
        if(temp & 1)
            odd.push_back(i+1);
        else
            even.push_back(i+1);
    }
    if(odd.size() == 0)
    {
        cout<<"NO\n";
    }
    else
    {
        //3 odd
        if(odd.size()>=3)
        {
            cout<<"YES\n";
            cout<<odd[0]<<" "<<odd[1]<<" "<<odd[2]<<"\n";
        }
        //2 even 1 odd
        else if(even.size() >= 2 && odd.size()>=1)
        {
            cout<<"YES\n";
            cout<<even[0]<<" "<<even[1]<<" "<<odd[0]<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}