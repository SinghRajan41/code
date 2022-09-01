#include<iostream>
using namespace std;
//Row Major
/*class matrix
{
   int *a,n;
   public:
   matrix(int s){a=new int[s*(s+1)/2];}
   void set(int i,int j,int value)
   {
      if(i>=j)
      {
         *(a + i*(i+1)/2 +j)=value;
      }
      else
      {
         return;
      }
   }

   int get(int i,int j)
   {
         if(i>=j)
         {
            return *(a + i*(i+1)/2 +j);
         }
         else
         {
            return 0;
         }
   }

   
};
int main()
{
   int n;
   cout<<"Enter the dimension=";
   cin>>n;
   matrix m(n);
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         int temp;
         cin>>temp;
         m.set(i,j,temp);

      }
   }

   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         cout<<m.get(i,j)<<" ";
      }
      cout<<endl;
   }
   return 0;
}*/




//Column Major
class matrix
{
   int *a,n;
   public:
   matrix(int s)
   {n=s;
      a=new int[s*(s+1)/2];
   }
   ~matrix()
   {
      delete []a;
      a=NULL;
   }

   void set(int i,int j,int x)
   {
      if(i>=j)
      {
         *(a +(j/2)*(2*n + 1-j) + i-j)=x;
      }
   }

   int get(int i,int j)
   {
      if(i>=j)
      {
         return *(a +(j/2)*(2*n + 1-j) + i-j);
      }
      return 0;
   }
};
int main()
{
   int n,temp;
   cout<<"Enter the dimensions of the matrix=";
   cin>>n;
   matrix m(n);
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
       // cin>>temp;
        m.set(i,j,i+j);
      }
   }

   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         cout<<m.get(i,j)<<" ";
      }
      cout<<endl;
   }
   return 0;
}