#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string infixToPostfix(string inf);
int osprec(char x);
int isprec(char x);
bool isoperator(char x);
bool operand(char x);
void solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)  cin>>arr[i];
    ll ops = 0;
    ll a = arr[n-1];
    for(int i = n-2;i>=0;--i)
    {
        if(arr[i] > a)
        {
            a = arr[i];
            ++ops;
        }
    }
    cout<<ops<<endl;
}
bool isoperand(char x)
{
    return (x>='a'&&x<='z') || (x>='0' && x<='9') || (x>='A' && x<='Z');
}
string infixToPostfix(string inf)
{
    stack<char> s;
    string pf = "";
    for(auto i:inf)
    {
        if(isoperator(i))
        {
            if(s.empty())
            {
                s.push(i);
            }
            else
            {
                while(!s.empty() && osprec(i) < isprec(s.top()) && s.top() != '(')
                {
                    pf.push_back(s.top());
                    s.pop();
                }
                s.push(i);
            }
        }
        else if(isoperand(i))
        {
            pf.push_back(i);
        }
        else if(i == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                pf.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty())
    {
        pf.push_back(s.top());
        s.pop();
    }
    return pf;
}
int osprec(char x)
{
    if(x=='+' || x== '-') return 2;
    else if(x=='*' || x=='/') return 4;
    else if(x=='^') return 7;
    else if(x=='(') return 10;
    else  return -1;
}
int isprec(char x)
{
    if(x=='+' || x== '-') return 3;
    else if(x=='*' || x=='/') return 5;
    else if(x=='^') return 6;
    else if(x=='(') return 0;
    else  return -1;
}
bool isoperator(char x)
{
    char arr[] = {'+' , '-' , '*' , '^' , '(', '/'};
    for(int i = 0;i<6;i++)
    {
        if(arr[i] == x)
            return true;
    }
    return false;
}
