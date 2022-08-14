#include <iostream>
#include <string>
using namespace std;
char *infix_to_postfix(string infix);
int isOperator(char x);
int isprec(char x);
int osprec(char x);
template <class X>
class node
{
public:
   X data;
   node<X> *next;
};
template <class X>
class stack
{
   node<X> *top, *a, *b, *c;

public:
   stack()
   {
      top = NULL;
   }
   void push(X value)
   {
      a = new node<X>;
      a->next = NULL;
      a->data = value;
      if (top == NULL)
      {
         top = a;
      }
      else
      {
         a->next = top;
         top = a;
      }
   }
   X pop()
   {
      X junk;
      if (top != NULL)
      {
         junk = top->data;
      }
      a = top;
      top = top->next;
      delete a;
      return junk;
   }
   int isEmpty()
   {
      return top == NULL ? 1 : 0;
   }
   X topp()
   {
      return top->data;
   }
};
int main()
{
   string infix;
   cout << "\nEnter the infix Expression=";
   getline(cin >> ws, infix);
   char *pf = infix_to_postfix(infix);
   cout << endl;
   while (*pf != '\0')
   {
      cout << *pf;
      pf++;
   }
   return 0;
}
char *infix_to_postfix(string infix)
{
   char *pf = new char[infix.size() + 5];
   int j = 0;
   stack<char> s;
   infix = '(' + infix + ')';
   for (int i = 0; i < infix.size(); i++)
   {
      if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
      {
         pf[j++] = infix[i];
      }
      else if (isOperator(infix[i]))
      {
         if (osprec(infix[i]) > isprec(s.topp()))
         {
            s.push(infix[i]);
         }
         else
         {
            while (osprec(infix[i]) > isprec(s.topp()))
            {
               pf[j++] = s.pop();
            }
         }
      }
      else
      {
         if (infix[i] == '(')
         {
            s.push(infix[i]);
            continue;
         }
         if (infix[i] == ')')
         {
            while (s.topp() != '(')
            {
               pf[j++] = s.pop();
            }
            s.pop();
            continue;
         }
      }
   }
   pf[j++] = '\0';
   return pf;
}
int isprec(char x)
{
   switch (x)
   {
   case '+':
      return 2;
   case '-':
      return 2;
   case '*':
      return 4;
   case '/':
      return 4;
   case '^':
      return 5;
   case '(':
      return 0;
   }
   return -1;
}
int osprec(char x)
{
   switch (x)
   {
   case '+':
      return 1;
   case '-':
      return 1;
   case '*':
      return 3;
   case '/':
      return 3;
   case '^':
      return 6;
   case '(':
      return 8;
   }
   return -1;
}
int isOperator(char x)
{
   if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
   {
      return 1;
   }
   else
   {
      return 0;
   }
}