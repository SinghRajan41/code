// A sphenic number is a number which is a product of exactly three prime numbers
#include <iostream>
#include <cstring>
using namespace std;
bool seive[100001];
int N = 100001;
void initialiseSeive();
bool isSphenic(int n);
int main()
{
   int n;
   cin >> n;
   initialiseSeive();
   cout << (isSphenic(n) ? "Sphenic Number" : "Not a sphenic Number");
   return 0;
}
void initialiseSeive()
{
   memset(seive, 1, N);
   for (int i = 2; i < N; i++)
   {
      if (seive[i])
      {
         for (int j = 2 * i; j < N; j += i)
         {
            seive[j] = false;
         }
      }
   }
}
bool isSphenic(int n)
{
   if (seive[n])
   {
      return false;
   }
   int arr[3];
   int k = 0;
   int i = 2;
   while (n > 1)
   {
      while (n % i == 0)
      {
         arr[k++] = i;
         n /= i;
      }
      i++;
   }
   int a, b, c;
   a = arr[0];
   b = arr[1];
   c = arr[2];
   cout << a << " " << b << " " << c << endl;
   if (a == b || b == c || a == c || !seive[a] || !seive[b] || !seive[c])
   {
      return false;
   }
   else
   {
      return true;
   }
}