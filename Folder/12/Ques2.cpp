#include <iostream>
using namespace std;
int kthSmallest(int L1[], int L2[], int n, int m, int k);
int main()
{
   int n, m;
   cout << "Enter the size of L1 list = ";
   cin >> n;
   cout << "Enter the size of L2 list = ";
   cin >> m;
   int L1[n], L2[m];
   cout << "\nEnter the elements of L1 = ";
   for (int i = 0; i < n; i++)
   {
      cin >> L1[i];
   }
   cout << "\nEnter the elements of L2 = ";
   for (int i = 0; i < m; i++)
   {
      cin >> L2[i];
   }
   cout << "\nEnter the value of K = ";
   int k;
   cin >> k;
   cout << k << "th smallest element in L1 U L2 =" << kthSmallest(L1, L2, n, m, k);
   return 0;
}
int kthSmallest(int L1[], int L2[], int n, int m, int k)
{
   int Max = -999999;
   for (int i = 0; i < n; i++)
   {
      if (L1[i] > Max)
         Max = L1[i];
   }
   for (int i = 0; i < m; i++)
   {
      if (L2[i] > Max)
      {
         Max = L2[i];
      }
   }
   int freq[Max + 1];
   for (int i = 0; i < Max + 1; i++)
   {
      freq[i] = 0;
   }
   for (int i = 0; i < n; i++)
   {
      freq[L1[i]] += 1;
   }
   for (int i = 0; i < m; i++)
   {
      freq[L2[i]] += 1;
   }
   for (int i = 0; i < Max + 1; i++)
   {
      if (freq[i] > 0)
      {
         k -= 1;
         if (k == 0)
         {
            return i;
         }
      }
   }
   return -1;
}