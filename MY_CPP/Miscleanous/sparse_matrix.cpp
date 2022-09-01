#include<iostream>
using namespace std;
struct element
{
   int i,j,x;
};
struct sparse
{
   int r,c,n;
   element *arr;
};
void create(sparse &s)
{
   //cout<<"Enter the dimensons of diary R C=";
   cin>>s.r>>s.c;
   //cout<<"Enter the number of non zero elements=";
   cin>>s.n;
   //cout<<"Now Enter Elements\n";
   s.arr=new element[s.n];
   for(int i=0;i<s.n;i++)
   {
     //cout<<"Row=";
     cin>>s.arr[i].i;
     //cout<<"Column=";
     cin>>s.arr[i].j;
     //cout<<"Element=";
     cin>>s.arr[i].x;
   }
}

void display(sparse &s)
{
   int k=0;
   for(int i=0;i<s.r;i++)
   {
      for(int j=0;j<s.c;j++)
      {
       if(s.arr[k].i==i+1 && s.arr[k].j==j+1)
       {
          cout<<s.arr[k].x<<" ";
          k++;
       }
       else
       {
          cout<<0<<" ";
       }
      }
      cout<<endl;
   }
}
sparse add(sparse &s1,sparse &s2)
{
   sparse s3;
   s3.r=s1.r;
   s3.c=s1.c;
   s3.n=s1.n + s2.n;
   s3.arr=new element[s3.n];
   int i=0,j=0,k=0;
   while(i<s1.n && j<s2.n)
   {
      if(s1.arr[i].i < s2.arr[j].i)
      {
         s3.arr[k].i= s1.arr[i].i;
         s3.arr[k].j=s1.arr[i].j;
         s3.arr[k].x=s1.arr[i].x;
         k++;i++;
      }
      else if(s1.arr[i].i > s2.arr[j].i)
      {
         s3.arr[k].i=s2.arr[j].i;
         s3.arr[k].j=s2.arr[j].j;
         s3.arr[k].x=s2.arr[j].x;
         j++;k++;
      }
      else if(s1.arr[i].i == s2.arr[j].i)
      {
         if(s1.arr[i].j < s1.arr[j].j)
         {
            s3.arr[k].i=s1.arr[i].i;
            s3.arr[k].j=s1.arr[i].j;
            s3.arr[k].x=s1.arr[i].x;
            i++;k++;
         }
         else if(s1.arr[i].j > s2.arr[j].j)
         {
            s3.arr[k].i=s2.arr[j].i;
            s3.arr[k].j=s2.arr[j].j;
            s3.arr[k].x=s2.arr[j].x;
            j++;
            k++;
         }
         else
         {
            s3.arr[k].i=s1.arr[i].i;
            s3.arr[k].j=s1.arr[i].j;
            s3.arr[k].x=s1.arr[i].x + s2.arr[j].x;
            i++;j++;k++;
         }
      }
      while(i<s1.n)
      {
         s3.arr[k].i=s1.arr[i].i;
         s3.arr[k].j=s1.arr[i].j;
         s3.arr[k].x=s1.arr[i].x;
         k++;i++;
      }
      while(j<s2.n)
      {
         s3.arr[k].i=s2.arr[k].i;
         s3.arr[k].j=s2.arr[k].j;
         s3.arr[k].x=s2.arr[k].x;
         k++;j++;
      }
   }
   s3.n=k;
   return s3;
   
}
int main()
{
  sparse s1,s2;
  create(s1);create(s2);
  sparse s3=add(s1,s2);
  display(s1);
  cout<<endl;
  display(s2);cout<<endl;
  display(s3);
  return 0;
}