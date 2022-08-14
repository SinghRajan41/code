/*#include <iostream>
#include <cmath>
using namespace std;
class ht
{
   int *arr, size = 0, keys;

public:
   ht(int n)
   {
      keys = n;
      // Making sieve of eratosthenes
      int x = floor(2.5 * (double)n);
      bool s[x];
      for (int i = 0; i < x; i++)
      {
         s[i] = 1;
      }
      for (int i = 2; i < x; i++)
      {
         if (s[i] == 1)
         {
            for (int j = 2 * i; j < x; j += i)
            {
               s[j] = 0;
            }
         }
      }
      for (int i = x - 1; i >= 2; i--)
      {
         if (s[i])
         {
            size = i;
            break;
         }
      }
      arr = new int[size];
      for (int i = 0; i < size; i++)
      {
         arr[i] = -1;
      }
   }
   void insert(int value);
   void display();
   void search(int value);
};
void ht::display()
{
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
}
void ht::insert(int value)
{
   int flag = 0, x = value % size;
   for (int i = 0; i < size; ++i)
   {
      int idx = x + i * i;
      if (arr[idx] == -1)
      {
         arr[idx] = value;
         flag++;
         return;
      }
   }
   if (!flag)
   {
      cout << "\nNo empty space left";
   }
}
int main()
{
   ht hst(12);
   hst.insert(21);
   hst.insert(1);
   hst.insert(9);
   hst.insert(28);
   hst.insert(37);
   hst.insert(43);
   hst.insert(69);
   hst.insert(83);
   hst.insert(85);
   hst.insert(105);
   hst.insert(66);
   hst.insert(81);
   hst.display();
   return 0;
}*/
#include <iostream>
using namespace std;
class Hash
{
   int *arr, size, keys;

public:
   Hash(int n)
   {
      keys = n;
      n = 2 * n + 10;
      // Generating Seive
      bool s[n];
      for (int i = 0; i < n; i++)
      {
         s[i] = 1;
      }
      for (int i = 2; i < n; i++)
      {
         if (s[i] == 1)
         {
            for (int j = i * i; j < n; j += i)
            {
               s[j] = 0;
            }
         }
      }
      for (int i = n - 1; i > 1; --i)
      {
         if (s[i] == 1)
         {
            size = i;
            break;
         }
      }
      arr = new int[size];
      for (int i = 0; i < size; i++)
      {
         arr[i] = -1;
      }
   }
   void display();
   void insert(int value);
};
void Hash::insert(int value)
{
   int idx;
   for (int i = 0; i < size; i++)
   {
      idx = (value % size + i * i) % size;
      if (arr[idx] == -1)
      {
         arr[idx] = value;
         return;
      }
   }
   cout << "No Space/Unresolved Collision\n";
}
void Hash::display()
{
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
}
int main()
{
   Hash h(25);
   h.insert(1);
   h.insert(51);
   h.insert(61);
   h.display();
   return 0;
}