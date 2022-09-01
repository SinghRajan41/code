#include<iostream>
#include "cstring"
using namespace std;
struct node
{
   char data;
   node *next;
};
class stack
{
   node *top,*a;
   public:
   stack(){top=NULL;}
   void push(char value);
   char pop();
   int isEmpty();
};
void stack::push(char value)
{
   a=new node;
   if(a==NULL)
   {
      cout<<"Stack OverFlow";
      return;
   }
   else
   {
      a->data=value;
      a->next=top;
      top=a;
   }
}
int stack::isEmpty()
{
   int x=(top==NULL)? 1:0;
   return x;
}
char stack::pop()
{
   char c='?';
   c=(top==NULL) ? c:top->data;
   a=top;
   top=top->next;
   delete a;
   return c;
}
int main()
{
   char exp[100]="[{(a+b)*2} / {21+32 * (34 /2)}]";
   stack s;
   for(int i=0;exp[i]!='\0';i++)
   {
      
      if(exp[i] == '[' || exp[i]=='(' || exp[i]=='{')
      {
         s.push(exp[i]);
         continue;
      }
      else if(exp[i] == ']' || exp[i]=='}' || exp[i]==')')
      {
        char ch=s.pop();
        if(exp[i]==']' && ch =='[' || exp[i]=='}' && ch =='{' ||exp[i]==')' && ch =='(')
        {continue;}
        else
        {
           s.push(ch);
        }
      }
   }
   puts(exp);
   cout<<(s.isEmpty() ? "Valid Expression\n" : "Invalid Expression\n");
}