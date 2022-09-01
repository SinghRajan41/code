#include<iostream>
using namespace std;
class toeplitz
{
   int *a,n,add;
   public:
   toeplitz(int s)
   {
      n=s;
      a=new int[2*n -1];
   }
   ~toeplitz()
   {
      delete []a;
      a=NULL;
   }
   void set(int i,int j,int value)
   {
     if(i==j)
     {
        *a=value;
     }
     else if(i<j)
     {
        *(a + j-i)=value;
     }
     else if(i>j)
     {
        *(a +n +i-j)=value;
     }
     
   }
   int get(int i,int j)
   {
     if(i==j)
     {
        return *(a);
     }
     else if(i>j)
     {
        return *(a + n + i-j);
     }
     else if(i<j)
     {
        return *(a + j-i);
     }
   }
};
int main()
{
 toeplitz m(5);
 for(int i=0;i<5;i++)
 {
    for(int j=0;j<5;j++)
    {
      m.set(i,j,i+j);
    }
 }

 for(int i=0;i<5;i++)
 {
    for(int j=0;j<5;j++)
    {
       cout<<m.get(i,j)<<" ";
    }
    cout<<endl;
 }
 return 0;
}