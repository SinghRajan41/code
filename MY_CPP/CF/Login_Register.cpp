#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define isAlpha(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
#define isNum(x) (x >= '0' && x <= '9')
#define isSpec(x) ((x >= '!' && x <= '/') || (x >= ':' && x <= '@'))
using namespace std;

void encodeString(string &s)
{
   char ch = 5;
   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] != ch)
      {
         s[i] += 20;
      }
   }
}
void printMessage()
{
   cout << "\nChoose  atleast 6 character long \npassword containing  NUMBERS ,  ALPHABETS   and   SPECIAL   characters\n";
   cout << "Enter password again=";
}
bool validatePassword(string &s)
{
   bool len, num, alpha, spec;
   len = num = alpha = spec = false;
   len = (s.size() < 6) ? false : true;

   for (int i = 0; i < s.size(); i++)
   {
      if (isNum(s[i]))
      {
         num = true;
         break;
      }
   }
   for (int i = 0; i < s.size(); i++)
   {

      if (isAlpha(s[i]))
      {
         alpha = true;
         break;
      }
   }
   for (int i = 0; i < s.size(); i++)
   {

      if (isSpec(s[i]))
      {
         spec = true;
         break;
      }
   }

   return (len && num && alpha && spec);
}
void decodeString(string &s)
{
   char ch = 5;
   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] != ch)
      {
         s[i] -= 20;
      }
   }
}
void Register();
void login();
int main()
{
   char ch = 'y';
   while (ch == 'y' || ch == 'Y')
   {
      cout << "\n1-> Login";
      cout << "\n2-> Register";
      cout << "\n3-> Exit\n";
      int x;
      cin >> x;
      switch (x)
      {
      case 1:
         login();
         break;
      case 2:
         Register();
         break;
      case 3:
         return 0;
         break;
      default:
         cout << "\nEnter a valid choice=";
         break;
      }
      cout << "\nDo you wish to continue? (y/n)=";
      cin >> ch;
   }

   return 0;
}
void login()
{
   ifstream f;
   string id, pd;
   f.open("users.txt", ios::in);
   cout << "\nEnter user id=";
   getline(cin >> ws, id);
   cout << "\nEnter password=";
   getline(cin >> ws, pd);
   char ch = 5;
   while (!f.eof())
   {
      string s;
      getline(f, s);
      decodeString(s);
      stringstream stream(s);
      string name1, id1, pd1;
      getline(stream, name1, ch);
      getline(stream, id1, ch);
      getline(stream, pd1, ch);
      if (id1 == id && pd1 == pd)
      {
         cout << "\nWelcome " << name1 << endl;
         f.close();
         return;
      }
   }
   cout << "\n Sorry User not Avalaible";
   f.close();
}
void Register()
{
   string s = "";
   string temp;
   char ch = 5;
   cout << "\nEnter your fullname=";
   getline(cin >> ws, temp);
   s += temp;
   s.append(&ch, &ch + 1);
   cout << "\nSelect a user id=";
   getline(cin, temp);
   s += temp;
   s.append(&ch, &ch + 1);
   cout << "\nSelect a password=";
   getline(cin, temp);
   while (!validatePassword(temp))
   {
      printMessage();
      getline(cin, temp);
   }
   s += temp;
   s.append(&ch, &ch + 1);
   ofstream f;
   f.open("users.txt", ios::app);
   encodeString(s);
   f << s << endl;
   f.close();
   cout << "\nYou have successfully registered!\nYou can login now";
   cout << "\033[2J\033[1;1H";
}
