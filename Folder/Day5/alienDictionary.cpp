#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define Lower(x) (x >= 'a' && x <= 'z')
void printAlienOrder(string words[], int n);
void capitalise(string words[], int n);
void printAlienOrder(string words[], int n);
void dfs(int g[26][26], int cur, bool visited[], stack<int> &s);
int main()
{
   int n;
   cin >> n;
   string words[n];
   for (int i = 0; i < n; i++)
   {
      getline(cin >> ws, words[i]);
   }
   printAlienOrder(words, n);
   return 0;
}
void capitalise(string words[], int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < words[i].size(); j++)
      {
         if (Lower(words[i][j]))
         {
            words[i][j] -= 32;
         }
      }
   }
}
void printAlienOrder(string words[], int n)
{
   capitalise(words, n);
   int g[26][26];
   for (int i = 0; i < 26; i++)
   {
      for (int j = 0; j < 26; j++)
      {
         g[i][j] = -1;
      }
   }
   for (int i = 0; i < n - 1; i++)
   {
      string cur = words[i];
      string next = words[i + 1];
      int len = min(cur.size(), next.size());
      for (int j = 0; j < len; j++)
      {
         if (cur[j] != next[j])
         {
            g[cur[j] - 65][next[j] - 65] = 1;
            break;
         }
      }
   }
   stack<int> s;
   // Writing code to store the topological sort order of the given graph
   bool visited[26];
   for (int i = 0; i < 26; i++)
   {
      visited[i] = false;
   }
   for (int i = 0; i < 26; i++)
   {
      for (int j = 0; j < 26; j++)
      {
         if (g[i][j] != -1 && !visited[i])
         {
            dfs(g, i, visited, s);
         }
      }
   }
   while (!s.empty())
   {
      cout << (char)(97 + s.top()) << " ";
      s.pop();
   }
}
void dfs(int g[26][26], int cur, bool visited[], stack<int> &s)
{
   if (!visited[cur])
   {
      visited[cur] = true;
      for (int i = 0; i < 26; i++)
      {
         if (g[cur][i] != -1)
         {
            dfs(g, i, visited, s);
         }
      }
      s.push(cur);
   }
}