#include<iostream>
using namespace std;
class tri_diagonal
{
   int *a,n,add;
   public:
   tri_diagonal(int s)
   {
      n=s;
      a=new int[3*n - 2];
   }
   ~tri_diagonal()
   {
      delete []a;
      a=NULL;
   }
   void set(int i,int j,int value)
   {
     if(i==j)
     {
        *(a + n-1 + i)=value;
     }
     else if(i-j == 1)
     {
        *(a +j)=value;
     }
     else if(i-j == -1)
     {
        *(a + 2*n -1 +i)=value;
     }
     else 
     {
        return;
     }
   }
   int get(int i,int j)
   {
     if(i==j)
     {
        return *(a + n-1 +i);
     }
     else if(i-j ==1)
     {
        return *(a +j);
     }
     else if(i-j == -1)
     {
        return *(a + 2*n -1 +i);
     }
     else
     {
        return 0;
     }
   }
};
int main()
{
   tri_diagonal m(5);
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         m.set(i,j,5);
      }
      cout<<endl;
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
