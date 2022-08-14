#include<iostream>
using namespace std;
void A(int n);
void B(int n);
void C(int n);

void A(int n)
{
   if(n>0)
   {
      cout<<n<<" ";
      B(n-1);
   }
}
void B(int n)
{
   if(n>0)
   {
      cout<<n<<" ";
      C(n/2);
   }
}
void C(int n)
{
   if(n>1)
   {
    cout<<n<<" ";
    A(n-1); 
   }
}
int main()
{
   A(200);
   return 0;
}