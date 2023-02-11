#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string infixToPostfix(string inf);
int osprec(char x);
int isprec(char x);
bool isoperator(char x);
bool operand(char x);
void solve(string &s);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
    return 0;
}
void solve(string &str)
{
    int n = str.length();
    //ll num = stoi(str);
    /*if(num % 25 == 0)
    {
        cout<<0<<endl;
        return;
    }*/
    char s[n+1];
    s[0] = '0';
    for(int i = 0;i<n;i++)s[i+1] = str[i];
    vector<int> zero(20,-100),two(20,-100),five(20,-100),seven(20,-100);
    zero[0] = two[0] = five[0] = seven[0] = -100;
    for(int i = 1;i<=n;i++)
    {
        if(s[i] == '0')
        {
            zero[i] = i;
            two[i] = two[i-1];
            five[i] = five[i-1];
            seven[i] = seven[i-1];
        }
        else if(s[i] == '2')
        {
            zero[i] = zero[i-1];
            two[i] = i;
            five[i] = five[i-1];
            seven[i] = seven[i-1];
        }
        else if(s[i] == '5')
        {
            zero[i] = zero[i-1];
            two[i] = two[i-1];
            five[i] = i;
            seven[i] = seven[i-1];
        }
        else if(s[i] == '7')
        {
            zero[i] = zero[i-1];
            two[i] = two[i-1];
            five[i] = five[i-1];
            seven[i] = i;
        }
        else
        {
            zero[i] = zero[i-1];
            two[i] = two[i-1];
            five[i] = five[i-1];
            seven[i] = seven[i-1];           
        }
       
    }
    ll ans = 100;
    for(int i = n; i>=1 ; i--)
    {
        if(s[i] == '0')
        {
            ans = min(ans ,(ll) n-i + i - zero[i-1]-1);
            ans = min(ans ,(ll) n-i + i -five[i]-1);
        }
        else if(s[i] == '5')
        {
            ans = min(ans ,(ll) n-i+i-two[i]-1);
            ans = min(ans ,(ll) n-i + i - seven[i] -1);
        }
    }
    cout<<ans<<"\n";
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