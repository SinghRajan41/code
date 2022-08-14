#include<bits/stdc++.h>
using namespace std;
int main()
{
  fstream f;
  f.open("hola.txt",ios::in);
  char ch;
  f.seekg(3,ios::beg);
  f.seekp(3,ios::beg);
  f>>ch;
  cout<<ch;
  f<<ch;
  f<<ch;
  
  return 0;
}