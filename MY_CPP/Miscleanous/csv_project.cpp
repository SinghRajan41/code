#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
vector<string> split(string s,int size)
{
   vector<string> v;
   string temp="";
   for(int i=0;i<size;i++)
   {
      if(s[i]==',')
      {
         v.push_back(temp);
         temp="";
      }
      else
      {
         temp=temp+s[i];
      }
   }
   v.push_back(temp);
   return v;
}
int main()
{
   fstream f;
   f.open("data.csv",ios::in);
   char str[100];
   string s;
   vector<string> v;
   while(!f.eof())
   {
    f.getline(s,100);
    int size=sizeof(str)/sizeof(str[0]);
    v=split(str,s.size());
    for(int i=0;i<v.size();i++)
    {
       cout<<v[i]<<" ";
    }
    cout<<endl;
   }
   f.close();
   return 0;
}
