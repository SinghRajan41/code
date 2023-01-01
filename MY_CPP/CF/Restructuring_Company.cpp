// Even the most successful company can go through a crisis period when you have to make a hard decision — to restructure, discard and merge departments, fire employees and do other unpleasant stuff. Let's consider the following model of a company.

// There are n people working for the Large Software Company. Each person belongs to some department. Initially, each person works on his own project in his own department (thus, each company initially consists of n departments, one person in each).

// However, harsh times have come to the company and the management had to hire a crisis manager who would rebuild the working process in order to boost efficiency. Let's use team(person) to represent a team where person person works. A crisis manager can make decisions of two types:

// Merge departments team(x) and team(y) into one large department containing all the employees of team(x) and team(y), where x and y (1 ≤ x, y ≤ n) — are numbers of two of some company employees. If team(x) matches team(y), then nothing happens.
// Merge departments team(x), team(x + 1), ..., team(y), where x and y (1 ≤ x ≤ y ≤ n) — the numbers of some two employees of the company.
// At that the crisis manager can sometimes wonder whether employees x and y (1 ≤ x, y ≤ n) work at the same department.

// Help the crisis manager and answer all of his queries.
#include<iostream>
using namespace std;
int *parent,n,q,t,a,b;
int find(int a){return (a==parent[a] ? a : parent[a] = find(parent[a]));}
int main()
{
    int *size;bool *isChild;
    cin>>n>>q;  parent = new int[n+1];  size = new int[n+1];    isChild = new bool[n+1];for(int i=0;i<=n;i++)   {parent[i] = i;size[i] = 1;isChild[i] = false;}
    for(int i=0;i<q;i++)    
    {
        cin>>t>>a>>b;
        if(t==1){if(a^b){a = find(a);    b = find(b);    if(size[b] > size[a])   swap(a,b);parent[b] = a;  size[a] += size[b];}}
        else if(t==2)
        {  
            for(int j=a+1;j<=b;j++) 
            { 
                int x = a;  int y = j;  x = find(x);    y = find(y);    
                if(size[y] > size[x])   
                    swap(x,y);  
                parent[y] = x;  size[x] += size[y];
            }
        }
        else    {cout<<((find(a)^find(b)) ? "NO\n" : "YES\n");}
    }
    return 0;
}
