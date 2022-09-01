#include<iostream>
using namespace std;
void subsets(string s,string ans)
{
   if(s.length()==0)
   {
      cout<<ans<<" ";
      return;
   }
   subsets(s.substr(1),ans);
   subsets(s.substr(1),ans+s[0]);
}

int main()
{
  char *s="raj";
  s++;s++;//s++;
  cout<<*s;
  return 0;
      
   }
