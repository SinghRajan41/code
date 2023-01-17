#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct item{int a;int b;int c;int d;};
item solve(int a[] , int b[],int c[],int d[],int na,int nb,int nc,int nd);
int lowerBound(int arr[] ,int size , double key);
int upperBound(int arr[],int size,double  key);
int style(int a,int b,int c,int d);
#define M 1e9
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int na,nb,nc,nd;    
    cin>>na;
    int a[na];  for(int i=0;i<na;i++)   cin>>a[i];
    cin>>nb;
    int b[nb];  for(int i=0;i<nb;i++)   cin>>b[i];
    cin>>nc;
    int c[nc];  for(int i=0;i<nc;i++)   cin>>c[i];
    cin>>nd;
    int d[nd];  for(int i=0;i<nd;i++)   cin>>d[i];
    item res = solve(a , b , c , d , na , nb , nc , nd);
    cout<<res.a<<" "<<res.b<<" "<<res.c<<" "<<res.d<<"\n";
    return 0;
}
int style(int a,int b,int c,int d)
{
    int arr[] = {a,b,c,d};
    sort(arr , arr+4);
    return arr[3] - arr[0];
}
item solve(int a[] , int b[],int c[],int d[],int na,int nb,int nc,int nd)
{
    item res;
    int p,q,r,s,t,l,u;
    int minDiff = INT32_MAX;
    sort(a , a+na);
    sort(b , b + nb);
    sort(c , c+nc);
    sort(d , d+nd);
    for(int i=0;i<na;i++)
    {
        double avg = a[i];
        p  = a[i];
        l = lowerBound(b , nb , avg);
        u = upperBound(b , nb , avg);
        if(l != M && u != M)
        {
            if(avg-l < u-avg)
                q = l;
            else
                q = u;
        }
        else if(l != M || u != M)
        {
            if(l == M)
                q = u;
            else
                q = l;
        }
        else
        {
            q = M;
        }
        avg = 1.0*(p + q) / 2;
        l = lowerBound(c , nc , avg);
        u = upperBound(c , nc , avg);
        if(l != M && u != M)
        {
            if(avg-l < u-avg)
                r = l;
            else
                r = u;
        }
        else if(l != M || u != M)
        {
            if(l == M)
                r = u;
            else
                r = l;
        }
        else
        {
            r = M;
        }
        avg = 1.0 * (p + q + r) / 3;
        l = lowerBound(d , nd , avg);
        u = upperBound(d , nd , avg);
        if(l != M && u != M)
        {
            if(avg-l < u-avg)
                s = l;
            else
                s = u;
        }
        else if(l != M || u != M)
        {
            if(l == M)
                s = u;
            else
                s = l;
        }
        else
        {
            s = M;
        }
        if(p!=M && q!=M && r!=M && s!=M && style(p,q,r,s) < minDiff)
        {
            minDiff = style(p,q,r,s);
            res = {p,q,r,s};
        }
    }
    return res;
}
int lowerBound(int arr[],int size , double key)
{
    int low = 0;
    int high = size - 1;
    int ans =   1e9;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        if(arr[mid] <= key)
        {
            low = mid + 1;
            ans = arr[mid];
        }
        else
            high = mid - 1;
    }
    return ans;
}
int upperBound(int arr[],int size,double key)
{
    int low = 0;
    int high = size - 1;
    int ans = 1e9;
    while(low <= high)
    {
        int mid = (low + high)>>1;
        if(arr[mid] >= key)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
/*
7
2 5 9 12 15 19 20
5
7 9 12 18 30
8
5 8 12 17 20 25 26 35
8 
5 20 21 25 29 35 38 43
*/