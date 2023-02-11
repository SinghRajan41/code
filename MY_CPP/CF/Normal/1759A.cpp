#include<iostream>
#include<cstring>
using namespace std;
bool solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
bool solve()
{
    char s[51];
    scanf("%s" , s);
    int n = strlen(s);
    if(n==1 && !(s[0]=='Y' || s[0]=='e' || s[0] == 's'))
        return false; 
    for(int i=0;i<n-1;i++)
    {
        if(s[i] == 'Y')
        {
            if(s[i+1] != 'e')
                return false;
        }
        else if(s[i] == 'e')
        {
            if(s[i+1] != 's')
                return false;
        }
        else if(s[i] == 's')
        {
            if(s[i+1] != 'Y')
                return false;
        }
        else
        {
            return false;
        }
    }
    return true;
}