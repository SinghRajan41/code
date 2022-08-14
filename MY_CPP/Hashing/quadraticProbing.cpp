#include <iostream>
using namespace std;
class hashMap
{
   int *arr, size, n;

public:
   hashMap()
   {
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
      if (n > 0.7 * size)
      {
         cout << "\nHashtable is Full\n";
      }
      else
      {
         n++;
         int pos = value % size;
         int i = 1;
         while (arr[pos] != -1 && arr[pos] != value)
         {
            pos = (pos + i * i) % size;
            i++;
         }
         arr[pos] = value;
      }
   }
};
int main()
{

   return 0;
}