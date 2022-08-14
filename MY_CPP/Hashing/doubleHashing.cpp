#include <iostream>
#include <unordered_map>
#include <vector>
#define hash1(x) (x % size)
#define hash2(x) PRIME - x % PRIME
using namespace std;
class hashMap
{
   int *arr, size, PRIME, n;

public:
   hashMap()
   {
      size = 10301;
      PRIME = 10289;
      n = 0;
      arr = new int[size];
      for (int i = 0; i < size; i++)
      {
         arr[i] = -1;
      }
   }
   hashMap(int x)
   {
      bool s[2 * x + 20] = {0};
      for (int i = 2; i * i < 2 * x + 20; i++)
      {
         if (s[i] == 0)
         {
            for (int j = i * i; j < 2 * x + 20; j += i)
            {
               s[j] = 1;
            }
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
      for (int i = size - 1; i > 0; i--)
      {
         if (s[i] == 0)
         {
            PRIME = i;
            break;
         }
      }
   }
   void insert(int value)
   {
      if (n > 0.75 * size)
      {
         cout << "\nHashTable is Full\n";
         return;
      }
      n++;
      for (int i = 0; i < size; i++)
      {
         int pos = (hash1(value) + i * hash2(value)) % size;
         if (arr[pos] == value)
         {
            return;
         }
         if (arr[pos] == -1)
         {
            cout << value << "\tinserted\n";
            arr[pos] = value;
            return;
         }
      }
   }
   void showHash()
   {
      for (int i = 0; i < size; i++)
      {
         cout << arr[i] << "  ";
      }
   }
   bool isPresent(int value)
   {
      for (int i = 0; i < size; i++)
      {
         int pos = (hash1(value) + i * hash2(value)) % size;
         if (arr[pos] == value)
         {
            return true;
         }
         if (arr[pos] == -1)
         {
            return false;
         }
      }
   }
};
vector<int> findPairs(int arr[], int n)
{
   // code here
   vector<int> res;
   bool hash[2][1000001];
   for (int i = 0; i < 2; i++)
   {
      for (int j = 0; j < 1000001; j++)
      {
         hash[i][j] = 0;
      }
   }

   for (int i = 0; i < n; i++)
   {
      if (arr[i] > 0)
      {
         hash[0][arr[i]] = 1;
      }
      if (arr[i] < 0)
      {
         hash[1][-arr[i]] = 1;
      }
   }
   for (int i = 0; i < n; i++)
   {
      // cout << "x ";
      if (arr[i] < 0 && hash[0][-arr[i]] == 1)
      {
         res.push_back(arr[i]);
         res.push_back(-1 * arr[i]);
         hash[0][-arr[i]] = hash[1][-arr[i]] = 0;
      }
      else if (arr[i] > 0 && hash[1][arr[i]])
      {
         res.push_back(-arr[i]);
         res.push_back(arr[i]);
         hash[0][arr[i]] = hash[1][arr[i]] = 0;
      }
   }

   return res;
}
int main()
{
   int n, x;
   cin >> n >> x;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   vector<int> res = findPairs(arr, n);
   for (int i = 0; i < res.size(); i++)
   {
      cout << res[i] << " ";
   }
   return 0;
}