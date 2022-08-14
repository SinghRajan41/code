#include<iostream>
using namespace std;
int main()

{
    int t;
    cin>>t;
    while(t--)
    {
     int n; 
     cin>>n;
     short int arr[n];
     int zero=0,one=0,a[n],b[n];
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
         if(arr[i])
         {
             one+=1;
         }
         else
         {
             zero+=1;
         }
         a[i]=one;
         b[i]=zero;
     }
     
     if(n%2 == 1)
     {
         cout<<"NO\n";continue;
     }
     else 
     {
         cout<<"YES\n";
     }
     if(zero == one)
     {
         cout<<1<<" "<<n<<endl;continue;
     }
     if(zero < one)
     {
         int req_one = n/2 - zero;
         int one_count=0,i1=0,i2;
         for(int i=0;i<n;i++)
         {
             if(arr[i]==0)
             {
                 one_count=0;
                 i1=i;
             }
             else
             {
                 one_count+=1;
                 if(one_count == req_one)
                 {
                     cout<<i1+21<<" "<<i1+1+req_one<<endl;break;
                 }
             }
         }
         
     }
     else
     {
         int req_zero  = n/2 - one;
         int zero_count=0,i1=0,i2;
         for(int i=0;i<n;i++)
         {
             if(arr[i]==1)
             {
                 zero_count=0;
                 i1=i;
             }
             else
             {
                 zero_count+=1;
                 if(zero_count == req_zero)
                 {
                     cout<<i1+2<<" "<<i1+1+req_zero<<endl;break;
                 }
             }
         }
         
     }
     
return 0;
}}
