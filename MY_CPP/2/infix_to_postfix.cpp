#include<iostream>
#include<cstring>
using namespace std;
class stack
{
   char *arr;
   int top,size;
   public:
   stack(int n)
   {
      size=n;
      arr = new char[n];
      top=-1;
   }
   void push(char value);
   char pop();
   char peektop();
   int isEmpty();
   int osprec(char expi);
   int isprec(char topp);
   int isoperator(char x);
   int isoperand(char x);
};
void stack::push(char value)
{
 if(top == size -1)
 {
    cout<<"Stack OverFlow\n";
 }
 else
 {
    arr[++top]=value;
 }
}
int stack::osprec(char expi)
{
   switch(expi)
   {
      case '+':case '-':return 1;
      case '*':case '/':case '%': return 3;
      case '(':return 7;
      case '^':return 6;
   }
   return 0;
}

int stack::isprec(char topp)
{
   switch(topp)
   {case '+':case '-':return 2;
      case '*':case '/':case '%': return 4;
      case '(':return 0;
      case '^':return 5;
   }
   return 0;
}
int stack::isoperand(char x)
{
   if((x>='A' && x<='Z') || (x>= 'a' && x<='z'))
   {
      return 1;
   }
   return 0;
}
int stack::isoperator(char x)
{
   if(osprec(x))
   {
      return 1;
   }
   return 0;
}
char stack::pop()
{
   char rvalue ='@';
   if(top>-1)
   {
      rvalue = arr[top];
      top--;
   }
   rvalue;
}
char stack::peektop()
{
   if(top == -1)
   {
      return '@';
   }
   else
   {
      return arr[top];
   }
}

int stack::isEmpty()
{
   if(top == -1)
   {
      return 1;
   }
   return 0;
}
int main()
{
   char exp[]="(a+b*c/(d+m-e/f+h*g))";
   stack s(strlen(exp));
   char pf[strlen(exp)+1];
   int k=0;
   for(int i=0;exp[i]!='\0';i++)
   {
     //Check if it is an operand
     if(s.isoperand(exp[i]))
     {
        pf[k]=exp[i];k++;
     }

     //Now Check for Operator
     else if(s.isoperator(exp[i]))
     {
        if(s.isEmpty()){s.push(exp[i]);continue;}
        if(s.osprec(exp[i]) > s.isprec(s.peektop()))
        {
            s.push(exp[i]);
        }
        else if(s.osprec(exp[i]) < s.isprec(s.peektop()))
        {
           while(s.osprec(exp[i]) < s.isprec(s.peektop()) && !s.isEmpty())
           {
              char ch=s.pop();
              pf[k]=ch;k++;
           }
        }
     }

     //Stack is Empty
     else if(s.isEmpty())
     {
        if(s.isoperator(exp[i]))
        {
           s.push(exp[i]);
        }
        if(s.isoperand(exp[i]))
        {
           pf[k]=exp[i];
           k++;
        }
     }

     //Check for )
     else if(exp[i] == ')')
     {
        while(s.peektop() != '(' && !s.isEmpty())
        {
           char ch=s.pop();
           cout<<ch;
           pf[k]=ch;k++;
        }
        if(s.peektop() == '(')
        {
           s.pop();
        }
        cout<<endl;

     }

     for(int j=0;j<k;j++){cout<<pf[j];}
     cout<<"\t"<<i<<endl;
   }
   pf[k]='\0'; 
   puts(pf);
   
   return 0;
}