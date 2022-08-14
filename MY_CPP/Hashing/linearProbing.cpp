#include <iostream>
using namespace std;
class hashMap
{
   // this hashmap is good for membership check
   // The hashmap will not allow duplicate entries
   // duplicate entries will be ignored
   int *arr, size, n;

public:
   hashMap()
   {
      // Default size of the hashmap is
      size = 10301;
      n = 0;
      arr = new int[size];
      for (int i = 0; i < size; i++)
      {
         arr[i] = -1;
      }
   }
   hashMap(int x)
   {
      bool s[2 * x + 20];
      for (int i = 0; i < 2 * x + 20; i++)
      {
         s[i] = 0;
      }
      for (int i = 2; i < 2 * x + 20; i++)
      {
         if (s[i] == 0)
            for (int j = i * i; j < 2 * x + 20; j += i)
            {
               s[j] = 1;
            }
      }
      for (int i = 2 * x + 19; i > 0; i--)
      {
         if (s[i] == 0)
         {
            size = i;
            break;
         }
      }
      n = 0;
      arr = new int[size];
      for (int i = 0; i < size; i++)
      {
         arr[i] = -1;
      }
   }
   void insert(int value)
   {
      if (n > 0.65 * size)
      {
         cout << "\nHash Table is Full\n";
         return;
      }
      else
      {
         n++;
         int pos = value % size;
         while (arr[pos] != -1 && arr[pos] != value)
         {
            pos = (pos + 1) % size;
         }
         arr[pos] = value;
         cout << value << " \t inserted\n";
      }
   }
   bool isPresent(int value)
   {
      int pos = value % size;
      while (arr[pos] != -1)
      {
         if (arr[pos] == value)
         {
            return true;
         }
         else
         {
            pos = (pos + 1) % size;
         }
      }
      return false;
   }
};
int main()
{
   hashMap h(20);
   for (int i = 0; i < 100; i++)
   {
      h.insert(21);
   }
   if (h.isPresent(21))
   {
      cout << "\n21 is present\n";
   }
   else
   {
      cout << "\n21 is not presenrt";
   }
   return 0;
}