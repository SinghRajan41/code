#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
   char ch;

  ifstream f1;
  f1.open("hola.txt",ios::in);
  ofstream f2;
  f2.open("hola_copy.txt",ios::out);

  while(f1)
  {
     f1.get(ch);
     f2.put(ch);
  }
  return 0;
}