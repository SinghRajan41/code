#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
class stack
{
  char *arr;
  int size,top;
  public:
  stack(int n)
  {
     size=n;
     arr=new char[n];
     top=-1;
  }
  void push(char value);
  char pop();
  char peektop();
  int isempty();
  int isprec(char x);
  int osprec(char x);
  int isoperand(char x);
  int isoperator(char x);
  int isoperator2(char x);
  void clear_stack();
};
char *pf;
int k=0;
int stack::isoperator2(char x)
{
char ops[]={'+','-','*','/','%','^'};
  for(int i=0;i<6;i++)
  {
    if(x==ops[i])
    {
      return 1+i;
    }
  }
  return 0;
}
void stack::clear_stack()
{
  top=-1;
}
void stack::push(char value)
{
  if(top==size-1)
  {
    cout<<"Stack OverFLow\n";
    return ;
  }
  else
  {
    top+=1;
    arr[top]=value;
  }
}
char stack::pop()
{
  if(top==-1)
  {
    cout<<"Stack UnderFlow\nReturning @";
    return '@';
  }
  else
  {
    char x=arr[top];
    top-=1;
    return x;
  }
}
char stack::peektop()
{
  if(top == -1)
  {
    cout<<"Stack Is EMpty\n";
    return '@';
  }
  else
  {
    return arr[top];
  }
}
int stack::isempty()
{
  if(top<=-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int stack::osprec(char x)
{
  switch(x)
  {
    case '+':case '-':return 1;
    case '*':case '/':case '%':return 3;
    case '^':return 6;
    case '(':return 7;
  }
}
int stack::isprec(char x)
{
  switch(x)
  {
    case '+':case '-':return 2;
    case '*':case '/':case '%':return 4;
    case '^':return 5;
    case '(':return 0;
  }
}
int stack::isoperand(char x)
{
  if(x>='0' && x<='9')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int stack::isoperator(char x)
{
  char ops[]={'+','-','*','/','%','^','('};
  for(int i=0;i<7;i++)
  {
    if(x==ops[i])
    {
      return 1;
    }
  }
  return 0;
}
int main()
{
  char exp[200]="(1+(6/3+2))";      
  stack s(strlen(exp));
  pf=new char[strlen(exp)];

  for(int i=0;exp[i] != '\0' ;i++)
  {
    if(s.isoperand(exp[i]))
    {
      pf[k]=exp[i];k++;continue;
    }
    else if(s.isoperator(exp[i]))
    {
      if(s.isempty())
      {
        s.push(exp[i]);continue;
      }
      else if (s.osprec(exp[i]) > s.isprec(s.peektop()))
      {
        s.push(exp[i]);
        continue;
      }
      else if(s.osprec(exp[i]) < s.isprec(s.peektop()))
      {
        while(s.osprec(exp[i]) < s.isprec(s.peektop()))
        {
          char x=s.pop();
          pf[k]=x;
          k++;
        }
        s.push(exp[i]);
      }
    }
    else if( exp[i] == ')')
    {
      while(s.peektop() != '(')
      {
        char x=s.pop();
        pf[k]=x;
        k++;
      }
      char x=s.pop();
    }
  }


  //Displaying postfix
  for(int i=0;i<k;i++)
  {
    //cout<<pf[i];
  }
  s.clear_stack();

  //Evaluating
  int arr[50],top=-1,res;
  for(int i=0;i<k;i++)
  {
    //If operand push
    if(pf[i]>='0' && pf[i]<='9')
    {
      top++;
      arr[top]=pf[i]-'0';
    }
    else
    {
      int n=s.isoperator2(pf[i]);
      int x=arr[top];top-=1;int y=arr[top];top-=1;
      switch(n)
      {
        case 1:
        res = x+y;break;
        case 2:
        res = x-y;break;
        case 3:
        res = x*y;break;
        case 4:
        res = x/y;break;
        case 5:
        res = x%y;break;
        case 6:
        res=pow(x,y);break;

      }
      top++;
      arr[top]=res;

    }
  }
  cout<<arr[0];
  return 0;
}
