#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        if((a[0] == 'y' || a[0]=='Y') && (a[1]=='e' || a[1] == 'E') && (a[2]=='s' || a[2]=='S'))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}