#include<iostream>
using namespace std;
//Upper Triangle Column Major
class upper_triangle
{
   int *a,n,add;
   public:
   upper_triangle(int s)
   {
      n=s;
      a=new int[n*(n+1)/2];
   }
   ~upper_triangle()
   {
      delete []a;
      a=NULL;
   }

   void set(int i,int j,int value)
   {
    if(i<=j)
    {
       add=i+ j*(j+1)/2;
       *(a+add)=value;
    }
   }
   int get(int i,int j)
   {
     if(i<=j)
     {
        add=i + j*(j+1)/2;
        return *(a + add);
     }
     else
     {
        return 0;
     }
   }
};
int main()
{
   upper_triangle m(5);
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



































//Upper Triangle Row Major
/*class upper_triangle
{
   int *a,n,add;
   public:
   upper_triangle(int s)
   {
      n=s;
      a=new int[n*(n+1)/2];
   }
   ~upper_triangle()
   {
      delete []a;
      a=NULL;
   }
   int get(int i,int j)
   {
    if(i<=j)
    {
       add=i*(2*n + 1-i);
       add=add/2;
       add=add+j-i;
       return *(a+add);
    }
    else
    {
       return 0;
    }
   }

   void set(int i,int j,int x)
   {
   if(i<=j)
   {
      add=i*(2*n + 1-i);
       add=add/2;
       add=add+j-i;
       *(a+add)=x;
   }
   }
};
int main()
{
   upper_triangle m(5);
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
}*/























//Lower Triangle Column Major
/*class lower_triangle
{
   int n,*a,add;
   public:
   lower_triangle(int s)
   {
      n=s;
      a=new int[n*(n+1)/2];
   }
   ~lower_triangle()
   {
      delete []a;
      a=NULL;
   }
   void set(int i,int j,int value)
   {
     add=j*(2*n + 1-j);
     add=add/2;
     add=add+(i-j);
     if(i>=j)
     {
        *(a+add)=value;
     }
   }
   int get(int i,int j)
   {
     add=j*(2*n + 1-j);
     add=add/2;
     add=add+(i-j);
     if(i>=j)
     {
        return *(a+add);
     }
     else
     {
        return 0;
     }
   }

};

int main()
{
   lower_triangle m(5);
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
}*/


































//Row Major
/*
class lower_triangle
{
   int n,*a;
   public:
   lower_triangle(int s)
   {
      n=s;
      a=new int [(n*(n+1))/2];
   }
   ~lower_triangle()
   {
      delete []a;
      a=NULL;
   }


   void set(int i,int j,int value)
   {
       if(i>=j)
       {
          *(a + i*(i+1)/2 +j)=value;
       }
   }
   int get(int i,int j)
   {
     if(i>=j)
     {
        return *(a+ i*(i+1)/2 +j);
     }
     else
     return 0;
   }
};
int main()
{
  lower_triangle m(5);
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
}*/