#include<iostream>
using namespace std;
bool solve();
bool check(int a[] , int b[] ,int n);
int main()
{
    int t;  cin>>t;
    while(t--)
    {
        cout<<(solve() ? "YES\n"  : "NO\n");
    }
    return 0;
}
bool check(int a[] , int b[] ,int n)
{
    int na,nb,ni;
    na = nb = ni = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == 1 && b[i] == 1)
        {
            ni++;
            na++;
            nb++;
        }
        else if(a[i] == 1 || b[i] == 1)
        {
            if(a[i])
                na++;
            else
                nb++;
        }
    }
    //cout<<na<< " "<<nb<<" "<<ni<<" \n";
    int x = na - ni;
    int y = nb - ni;
    if(x < n/2)
    {
        int d = n/2 - x;
        x += d;
        ni -= d;
        if(ni < 0)
            return false;
    }
    if(y < n/2)
    {
        int d = n/2 - y;
        y += d; ni -= d;
        if(ni < 0)
            return false;
    }
    //cout<<x<<" "<<y<<" ";
    //cout<<endl;
    return x>=(n/2) && y>= (n/2);
}
bool solve()
{
    int n;  cin>>n;
    int arr[n][5];
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
            cin>>arr[i][j];
    int a[n],b[n];
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            for(int k=0;k<n;k++)
                a[k] = arr[k][i], b[k] = arr[k][j];
            if(check(a , b , n))
                return true;
        }
    }
    return false;
}