#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
class employee
{
  string name;
  int age;string department;
  public:
  employee(){}
  employee(string s,int a,string d)
  {
    name=s;
    department=d;
    age=a;
  }
  friend ostream & operator<<(ostream &stream,employee obj);
  friend istream & operator>>(istream &str,employee &o);
};
ostream & operator<<(ostream &stream,employee obj)
{
  stream<<obj.name<<" "<<obj.department<<" "<<obj.age<<endl;
  return stream;
}

istream &operator>>(istream &str,employee &o)
{
  cout<<"Enter your name=";
  str>>o.name;
  cout<<"Enter your department=";
  str>>o.department;
  cout<<"Enter your age=";
  str>>o.age;
  return str;
}
int main()
{
  employee obj1,obj2;
  cin>>obj1>>obj2;
  
  cout<<obj1<<" "<<obj2;
  return 0;
}
