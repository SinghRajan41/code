#include <iostream>
#include <set>
using namespace std;
void printFrequency(set<int> s[], int n);
int main()
{
   cout << "Enter the number of sets = ";
   int n;
   set<int> *s;
   cin >> n;
   s = new set<int>;
   for (int i = 0; i < n; i++)
   {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++)
      {
         int temp;
         cin >> temp;
         s[i].insert(temp);
      }
   }
   cout << "Enter the value of k="; // K is the number whose frequency you want to find in the set of sets
   int k;
   cin >> k;
   printFrequency(s, n, k);
   return 0;
}
void printFrequency(set<int> s[], int size, int k)
{
   int freq[100001];
   for (int i = 0; i < 100001; i++)
   {
      freq[i] = 0;
   }
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < s[i].size(); i++)
      {
         freq[s[i][j]] += 1;
      }
   }
   cout << "Frequency of " << k << " = ";
   cout << freq[k];
}