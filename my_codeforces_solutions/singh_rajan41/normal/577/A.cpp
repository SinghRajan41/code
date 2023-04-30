#include<iostream>
using namespace std;
int f(int arr[],int n,double size,int k);
int main()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"1\n";
    }
    else
    {
        int a,b;
        a = b = 0;
        for(int i=1;i<=n;i++)
        {
            b += min(n , k/i);
            a += min(n , (k-1)/i);
            
        }
        //cout<<b<<" "<<a<<" ";
        cout<<(b-a)<<"\n";
    }
    return 0;
}
int f(int arr[],int n,double size,int k)
{
    int a = 0;
    for(int i=0;i<n;i++)
        a += (int)((1.0*arr[i])/size);
    return a>=k ? 1:0;
}