/*
There are n employees in a company, and in the current moment no one is a subordinate of any other one. 
That is, each employee is a boss of himself. We call a person a boss, if he is not a subordinate of anybody else.

You are to process two types of queries:

boss a becomes a subordinate of boss b (and no longer is a boss),
given an employee c, what is the number of his superiors we should pass to reach a boss?
In a query of the second type, if c is a boss, the answer is 0, otherwise it is some positive integer — the "depth" of the employee.
*/
#include<iostream>
#include<vector>
using namespace std;
int n,q;vector<vector<int>> f;
int parent[(int)3e5+1],level[(int)3e5+1];
int find(int a){return ((parent[a] == a) ? a : parent[a] = find(parent[a]));}
struct node{    int data;   node *next; };
node *newNode(int data){    node *temp = new node;  temp->next = NULL;  temp->data = data;  return temp;    }
class dq
{
    public:
    node *front,*last;
    dq(){front = last = NULL;}
    inline void merge(node *f , node *l){  last->next = f; last = l;   }
    inline void pushBack(int data){node *temp = new node;  temp->next = NULL;  temp->data = data;     if(front == NULL){  front = last = temp;   }   else    {   last->next = temp; last = last->next;  }}
    inline void clear()    {   front = last = NULL;    }
};
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin>>n>>q;	for(int i=0;i<=n;i++)	{	parent[i] = i;level[i] = 0;}
	dq f[n+1];  for(int i=0;i<=n;i++)   f[i].pushBack(i);
	for(int i=0;i<q;i++)
	{
		int t,a,b;	cin>>t>>a;
		if(t==1){	cin>>b;	a = find(a);	b = find(b);	
        if(a != b)  
        {	
            parent[a] = b;	   
            node *temp = f[a].front;
            while(temp != NULL)
            {
                level[temp->data]++;temp = temp->next;
            }
            f[b].merge(f[a].front , f[a].last);
            f[a].front = f[a].last = NULL;
        }
        }
		else{	cout<<level[a]<<"\n";}
	}
	return 0;
}



//APPROACH 2   APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2     APPROACH 2     APPROACH 2    APPROACH 2   APPROACH 2
//APPROACH 2   APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2     APPROACH 2     APPROACH 2    APPROACH 2   APPROACH 2
//APPROACH 2   APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2     APPROACH 2     APPROACH 2    APPROACH 2   APPROACH 2
//APPROACH 2   APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2    APPROACH 2     APPROACH 2     APPROACH 2    APPROACH 2   APPROACH 2
// #include<iostream>
// using namespace std;
// int parent[(int)3e5+1],depth[(int)3e5+1],n,q;
// struct item{int a;int level;};
// item find(int a);
// int main()
// {
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
//     cin>>n>>q;
//     for(int i=0;i<=n;i++){  parent[i] = i;  depth[i] = 0;   }
//     for(int i=0;i<q;i++)
//     {
//         int t;  cin>>t;
//         if(t == 1)
//         {
//             int a,b;    cin>>a>>b;
//             item x,y;   x = find(a);    y = find(b);
//             parent[x.a] = y.a;
//             depth[x.a] += (y.level + 1);
//         }
//         else
//         {
//             int a;  cin>>a; item x = find(a);
//             cout<<x.level<<"\n";
//         }
//     }
// }
// item find(int a)
// {
//     item r;
//     if(a == parent[a]){r = {a , 0};}
//     else{   item i = find(parent[a]);   i.level++;  depth[a] = max(depth[a] , i.level); r = {i.a , depth[a]};   }
//     return r;
// }