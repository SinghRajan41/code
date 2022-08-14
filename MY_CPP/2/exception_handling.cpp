/*#include<iostream>
using namespace std;
void func(int i)
{
   try
   {
    if(i>=0)
    {
       throw i;
    }
   }
   catch(int i)
   {
      cout<<"\nCaught an error:"<<i;
   }
   
}
int main()
{
  int arr[7]={-1,-4,3,2,0,-4,9};
  for(int i=0;i<7;i++)
  {
     func(arr[i]);
  }
   return 0;
   
}*/



//CREATING AN ARRAY CLASS
#include<iostream>
#include<string>
using namespace std;

class error
{
   
   string what;int i;
   public:
   error()
   {
      what="";
      i=0;
   }

   error(string s,int j)
   {
      what=s;
      i=j;
   }
   void show_error()
   {
      cout<<what;
      cout<<i<<endl;
   }
};

int main()
{
   int n;
   try
   {
   cout<<"\nEnter a positive number=";
   cin>>n;
   if(n<0)
   {
      error e("\nNot a positive Number:",n);
      throw e;
   }
   }

   catch(error e)
   {
    e.show_error();
   }
   return 0;

}