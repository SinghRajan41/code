#include<iostream>
#define ll long long int
using namespace std;
ll count(ll prev , ll cur , ll dest);
void Sort(string &s);
int main()
{
    string s;
    cin>>s;
    Sort(s);
    cout<<s;
    return 0;
}
void Sort(string &s)
{
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            char key = s[i];
            int idx = i;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]>='a' && s[j]<='z'  && s[j] < key )
                {
                    idx = j;
                    key = s[j];
                }
            }
            swap(s[i] , s[idx]);
        }
        else
        {
            char key = s[i];
            int idx = i;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]>='A' && s[j]<='Z'  && s[j] > key )
                {
                    idx = j;
                    key = s[j];
                }
            }
            swap(s[i] , s[idx]);
        }
    }
}