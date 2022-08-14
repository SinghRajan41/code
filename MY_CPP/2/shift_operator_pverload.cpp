#include <iostream>
#include <cstring>
using namespace std;
class phonebook {
// now private
char name[80];
int areacode;
int prefix;
int num;
public:
phonebook(char *n, int a, int p, int nm)
{
strcpy(name, n);
areacode = a;
prefix = p;
num = nm;
}
 ostream &operator<<(ostream &stream, phonebook o);
 /*{
stream << o.name << " ";
stream << "(" << o.areacode << ") ";
stream << o.prefix << "-" << o.num << "\n";
return stream; // must return stream
}*/
};
// Display name and phone number.
ostream &operator<<(ostream &stream, phonebook o)
{
stream << o.name << " ";
stream << "(" << o.areacode << ") ";
stream << o.prefix << "-" << o.num << "\n";
return stream; // must return stream
}

int main()
{
phonebook a("Ted", 111, 555, 1234);
phonebook b("Alice", 312, 555, 5768);
phonebook c("Tom", 212, 555, 9991);
cout << a << b << c;
return 0;
}