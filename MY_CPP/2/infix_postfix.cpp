#include<iostream>
#include<string>
#include<sstream>

int main()
{
    string str="a bc cde fghi jklmn lol  lawl";
    stringstream s(str);
    while(str)
    {
        getline(str,s,' ');
        cout<<str<<endl;
    }
    return 0;
}