#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class array
{
   int *a,temp,l,h,mid;
   int size,len;
   public:
   array()
   {
      len=0;size=10;
      a=new int [size];
   }
   ~array()
   {
      delete []a;
      a=NULL;
   }
   array(int si)
   {
      size=si;
      a=new int[si];
   }
   int maximum();
   int minimum();
   long long int sum();
   void push(int value);
   void append(int value);
   void display();
   void insert(int i,int value);
   void dlt(int i);
   int lsearch(int key);
   int bsearch(int key);
   void sort(bool reverse=false);
   void lshift();
   void rshift();
   void lrotate();
   void rrotate();
   void reverse();
   bool sorted();
   void left_side();//Puts negative elements on left side
   void swap(int &a,int &b);
   array concatenate(array b);
   array operator+(array b);
   array operator+(int x);
   array operator-(int x);
   array operator*(int x);
   array operator/(int x);
   int& operator[](int i);
   int length()
   {
      return len;
   }
   
};

int main()
{
array a,b;
for(int i=0;i<20;i++)
{
   a.push(i+1);
   b.push(i+21);
}
array c=a * 20;
for(int i=0;i<a.length();i++)
{
   cout<<a[i]<<" ";
}
return 0;
}
int & array::operator[](int i)
{
   if(i>=len || i< -len)
   {
      cout<<"Warning: Index out of Range";
   }
   return i>-1 ? *(a+i):*(a+len +i);
   
}
array array::operator*(int x)
{
   array lol;
   for(int i=0;i<this->len;i++)
   {
      lol.push(this->a[i]*x);
   }
   return lol;
}
array array::operator/(int x)
{
   array lol;
   for(int i=0;i<this->len;i++)
   {
      lol.push(this->a[i]/x);
   }
   return lol;
}
array array::operator-(int x)
{
   array lol;
   for(int i=0;i<this->len;i++)
   {
      lol.push(this->a[i]-x);
   }
   return lol;
}

array array::operator+(int x)
{
  array lol;
  for(int i=0;i<this->len;i++)
  {
     lol.push(this->a[i]+x);
  }
  return lol;
}

int  array::maximum()
{
      int rvalue;
      rvalue=-1000000;
      for(int k=0;k<len;k++)
      {
         rvalue= rvalue>a[k] ? rvalue:a[k];
      }
      return rvalue;
}
array array::operator+(array b)
{
   array lol;
   for(int i=0;i<this->len;i++)
   {
      lol.push(this->a[i]);
   }
   for(int i=0;i<b.len;i++)
   {
      lol.push(b.a[i]);
   }
   return lol;
}
int array::minimum()
{
   
   temp=1000000;
   for(int i=0;i<len;i++)
   {
      temp= temp<a[i] ? temp:a[i];
   }
   return temp;
}
long long int array::sum()
   {
      long long int rvalue=0;
      for(int i=0;i<len;i++)
      {
         rvalue+=a[i];
      }
      return rvalue;
   }

void array::push(int value)
   {
      if(len==size)
      {
         //Allocating a new memory
         int *temp=new int[2*size];
         size=2*size;
         for(int i=0;i<len;i++)
         {
            temp[i]=a[i];
         }
         delete []a;
         temp[len++]=value;
         a=&temp[0];
         temp=NULL;
      }
      else
      {
         a[len]=value;len++;
      }
   }
void array::reverse()
{
   temp=len/2;
   for(int i=0;i<temp;i++)
   {
      int t=a[i];
      a[i]=a[len-i-1];
      a[len-i-1]=t;
   }
}
void array::append(int value)
   {
      if(len==size)
      {
         //Allocating a new memory
         int *temp=new int[2*size];
         size=2*size;
         for(int i=0;i<len;i++)
         {
            temp[i]=a[i];
         }
         delete []a;
         temp[len++]=value;
         a=&temp[0];
         temp=NULL;
      }
      else
      {
         a[len++]=value;
      }
   }
   void array::display()
   {
      for(int i=0;i<len;i++)
      {
         cout<<a[i]<<" ";
      }
   }
   void array::insert(int i,int value)
   {
      //Case:1 size is not enough
      if(!(i>=0 && i<len))
      {
         cout<<"\nIndex out of range!";
         exit(0);
      }
      if(len==size)
      {
         int *temp=new int[2*size];
         size=2*size;
         for(int i=0;i<len;i++)
         {temp[i]=a[i];}
         a=temp;
         delete []a;
         temp=NULL;
      }
      for(int j=len-1;j>=i;j--)
      {
         a[j+1]=a[j];
      }
      a[i]=value;
      len++;
   }

   void array::dlt(int i)
   {
      if(!(i>=0 && i<len))
      {
         return;
      }
      for(int j=i;j<len-1;j++)
      {
         a[i]=a[i+1];
      }
      len--;
   }
   //Improvised Linear Search
   int array::lsearch(int key)
   {
      for(int i=0;i<len;i++)
      {
         if(a[i]==key)
         {
            return i;
         }
      }
      return -1;
   }

void array::sort(bool reverse)
   {
      if(!reverse)
      {
        int m,temp;
        for(int i=0;i<len;i++)
        {
           m=a[i];
           int idx=i;
           for(int j=i;j<len;j++)
           {
              if(m>a[j])
              {
                 m=a[j];
                 idx=j;
              }
            }
           temp=a[idx];
           a[idx]=a[i];
           a[i]=temp;
           
        }
      }
      else
      {
        int m,temp;
        for(int i=0;i<len;i++)
        {
           m=a[i];
           int idx=i;
           for(int j=i;j<len;j++)
           {
              if(m<a[j])
              {
                 m=a[j];
                 idx=j;
              }
            }
           temp=a[idx];
           a[idx]=a[i];
           a[i]=temp;
           
        }
      }
   }
void array::lshift()
{
   if(len<=1)
   {
      a[0]=0;
      return;
   }
   for(int i=1;i<len;i++)
   {a[i-1]=a[i];}
   a[len-1]=0;
}
void array::rshift()
{
   if(len==1)
   {
      a[0]=0;
      return;
   }
   for(int i=len-2;i>=0;i--)
   {
      a[i+1]=a[i];
   }
   a[0]=0;
}

void array::rrotate()
{
   if(len==1)
   {
      return;
   }
   temp=a[len-1];
for(int i=len-2;i>-1;i--)
{
   a[i+1]=a[i];
}
a[0]=temp;
}
void array::lrotate()
{
   if(len==1)
   {
      return;
   }
   temp=a[0];
   for(int i=1;i<len;i++)
   {
      a[i-1]=a[i];
   }
   a[len-1]=temp;
}
bool array::sorted()
{
   for(int i=0;i<len-1;i++)
   {
      if(a[i]>a[i+1])
      {
         return false;
      }
   }
   return true;
}
void array::swap(int &a,int &b)
{
   temp=a;
   a=b;
   b=temp;
}


void array::left_side()
{
   //This function arranges all the negative elements on left side and positive elements on right side of the array
   int l=0,h=len-1;
   while(l<h)
   {
      l=a[l]<0 ? l+1:l;
      h=a[h]>=0 ? h-1:h;
      if(l<h && a[l]>=0 && a[h]<0)
      {
         swap(a[l],a[h]);
      }
   }
}

int array::bsearch(int key)
{
 l=0;
 h=len-1;
 if(!this->sorted())
 {
    cout<<"\nArray is not sorted";
    return -1;
 }
 
 while(l<=h)
 {
    mid=(l+h)/2;
    if(a[mid]==key)
    {
      return mid;
    }
    else if(a[mid]>key)
    {
       h=mid-1;
    }
    else
    {
       l=mid+1;
    }

 }
 return -1;
}
array array::concatenate(array b)
{
   array lol;
   for(int i=0;i<this->len;i++)
   {
      lol.push(this->a[i]);
   }
   for(int i=0;i<b.len;i++)
   {
      lol.push(b.a[i]);
   }
   return lol;
}

