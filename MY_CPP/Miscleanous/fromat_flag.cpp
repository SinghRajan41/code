#include <iostream>
using namespace std;
void showflags(ios &strm) ;
int main()/*  w  ww  .  j  ava 2  s  . co m*/
{
   // Show default condition of format flags.
   cout << "Default settings for cout:\n";
   showflags(cout);
   // Set the right, showpoint, and fixed flags.
   cout.setf(ios::right | ios::showpoint | ios::fixed);
   // Show flags after call to setf().
   cout << "Flags after setting right, showpoint, and fixed:\n";
   showflags(cout);
   return 0;
}
// This function displays the status of the format flags
// for the specified stream.
void showflags(ios &strm)
{
   ios::fmtflags f;
   // Get the current flag settings.
   f = strm.flags();
   if(f & ios::boolalpha) cout << "boolalpha:\ton\n"; else cout << "boolalpha:\toff\n";
   
   if(f & ios::dec) cout << "dec:\t\ton\n";           else cout << "dec:\t\toff\n";
   if(f & ios::hex) cout << "hex:\t\ton\n";           else cout << "hex:\t\toff\n";
   if(f & ios::oct) cout << "oct:\t\ton\n";           else cout << "oct:\t\toff\n";
   if(f & ios::fixed) cout << "fixed:\t\ton\n";       else cout << "fixed:\t\toff\n";
   if(f & ios::scientific) cout << "scientific:\ton\n";else cout << "scientific:\toff\n";
   if(f & ios::right) cout << "right:\t\ton\n";       else cout << "right:\t\toff\n";
   if(f & ios::left) cout << "left:\t\ton\n";         else cout << "left:\t\toff\n";
   if(f & ios::internal) cout << "internal:\ton\n";   else cout << "internal:\toff\n";
   if(f & ios::showbase) cout << "showbase:\ton\n";   else cout << "showbase:\toff\n";
   if(f & ios::showpoint) cout << "showpoint:\ton\n"; else cout << "showpoint:\toff\n";
   if(f & ios::showpos) cout << "showpos:\ton\n";     else cout << "showpos:\toff\n";
   if(f & ios::uppercase) cout << "uppercase:\ton\n"; else cout << "uppercase:\toff\n";
   if(f & ios::unitbuf) cout << "unitbuf:\ton\n";     else cout << "unitbuf:\toff\n";
   if(f & ios::skipws) cout << "skipws:\t\ton\n";     else cout << "skipws:\t\toff\n";
   cout << " \n";
}