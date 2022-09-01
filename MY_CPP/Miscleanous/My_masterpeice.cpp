#include<bits/stdc++.h>
using namespace std;
const int SIZE=20;
template<class x>class stock
{
  private:
  x arr[SIZE];                                   //INTEGER ARRAY SIZE LENGTH
  int top;                                         //VARIABLE STORING INDEX OF TOP ELEMENT

  public:
  stock()
  {top=0;}

  void push()                                      // PUSH FUNCTION
  {
     if(top==SIZE)
     {
        cout<<"\nstock is Full";
        return;
     }
     x value;
     cout<<"\nEnter the value to push=";
     cin>>value;
     arr[top++]=value;
  }


  x pop()                                         //   POP FUNCTION
  {
     if(top==0)
     {
        cout<<"\nStack is now empty";
        return;
     }
     else
     {
        top--;
        return  arr[top+1];
     }
  }

  void display()
  {
     for(int i=0;i<top;i++)
     {
        cout<<arr[i]<<" ";
     }
     cout<<endl;
  }

  x & operator[](int i)
  {
     if(i>=0 && i<SIZE)
     {
        return arr[i];
     }
     else
     {
        cout<<"Index out of Range! Value Enterred is lost! Enter a valid Index Range";
        x n;
        return n;
     }
  }

};



int main()
{
   stock<string> s;
   int n=5;
   for(;n;n-=1)
   {
      s.push();
   }

   cout<<s[1]<<" "<<s[0];
   return 0;
}