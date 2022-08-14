#include<iostream>
using namespace std;
int C(int n,int r)
{
   if(r==n || r==0)
   {
      return 1;
   }
   else 
   return C(n-1,r-1) + C(n-1,r);
}
char ch[4]={' ','A','B','C'};
static int count=0;
void toh(int n,int a,int b,int c)
{
   
   if(n>0)
   {
      toh(n-1,a,c,b);
      cout<<ch[a]<<" to "<<ch[c]<<endl;
      count++;
      
      toh(n-1,b,a,c);
   }
}
void foo(int n,int sum)
{
   int k=0,j=0;
   if(n==0) return;

   k=n%10;
   j=n/10;
   sum+=k;
   foo(j,sum);
   cout<<k;
}
int main()
{
   //Evaluate 5C2
   int a=2048,sum=0;
   foo(a,sum);
   cout<<sum;
   return 0;
}