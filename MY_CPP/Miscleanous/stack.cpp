/*#include<iostream>
using namespace std;
const int SIZE=10;
 

class stack
{
   private:
   int top;
   int st[SIZE];

   public:
   stack()
   {top=0;}

   void push(int value)
   {
      if(top==SIZE)
      {
         cout<<"Stack is Full"<<endl;
         return;
      }
      st[top++]=value;
   }

   int pop()
   {
      if(top==0)
      {
         
         return -111;
      }
      else{
      top--;
      return st[top+1];
      }
   }

   void display()
   {
      for(int i=0;i<top;i++)
      {
         cout<<st[i]<<" ";
      }
      cout<<endl;
   }
};


int main()
{
   char ch='y';
   stack obj;
   int choice;
   do
   {
   cout<<"1) For Push\n 2) For Pop\n 3) Display  \n4) Exit";
   cin>>choice;


   
      if(choice==1)
         {int value;
         cin>>value;
         obj.push(value);
         }
      else if(choice==2)
       { int rvalue=obj.pop();
         if(rvalue==-111)
         {
            cout<<"Stack is empty\n";
         }
         else
         {cout<<rvalue<<endl;}
       }

      else if(choice==3)
      {
         obj.display();
      }
      else
      {
      cout<<"Invalid Choice!\n";
      }
         

      cout<<"Continue??";
      cin>>ch;
   
   }while(ch=='y' || ch=='Y');

   return 0;
   
}*/


#include<iostream>
using namespace std;
const int  SIZE=10;
template<class x> class stack
{
   private:
   int top;
   x st[SIZE];

   public:
   stack(){top=0;}
   x pop()
   {
      if(top==0)
      {
         return 6.999;
      }
      else
      {
         top--;
         return st[top+1];
      }
   }

   void push(x value)
   {
      if(top==SIZE)
      {
         cout<<"Stack is Full\n";
         return;
      }
      else
      {
         st[top++]=value;
      }
   }

   void display()
   {
      for(int i=0;i<top;i++)
      {
         cout<<st[i]<<" ";
      }
      cout<<endl;
   }
};

int main()
{
   stack<double> obj;
   char ch='y';
   int choice;
   do
   {
      cout<<"\n1) Push \n2)Pop \n3)Display \n4)Exit";
      cin>>choice;
      if(choice==1)
      {
         double value;
         cin>>value;
         obj.push(value);
      }
      else if(choice==2)
      {
         double rvalue=obj.pop();
         if(rvalue==6.999)
         {
            cout<<"Stack is empty";
         }
         else
         {cout<<rvalue<<"\n";}

      }

      else if(choice==3)
      {
         obj.display();
      }
      else
      {
         cout<<"\nInvalid Choice";
      }
      cout<<"Do you wish to continue??";
      cin>>ch;

   } while (ch=='y' || ch=='Y');
   return 0;
   

}