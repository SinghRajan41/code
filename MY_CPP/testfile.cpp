#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};
node *create(int arr[], int n);
void printLL(node *head);
node *groupedReverse(node *head, int k);
node *getLast(node *head);
bool detectCycle(node *head);
int main()
{
   node *head;
   int arr[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
   head = create(arr, 14);
   node *a = getLast(head);
   a->next = head;
   if (/*detectCycle(head)*/ 1)
   {
      cout << "\nCycle detected and removed";
   }
   else
   {
      cout << "\nNo Cycle Detedted";
   }
   cout << endl;
   printLL(head);
   return 0;
}
bool detectCycle(node *head)
{
   // Using a visited array to keep track of visited nodes
   node *p = head;
   bool visited[10000] = {0};
   visited[p->data] = 1;
   while (p != NULL)
   {
      if (visited[p->next->data] == 1)
      {
         break;
      }
      else
      {
         visited[p->next->data] = 1;
         p = p->next;
      }
   }
   if (p == NULL)
   {
      // No loop detected
      return false;
   }
   else
   {
      // Loop is detected
      p->next = NULL;
      return true;
   }
}
node *getLast(node *head)
{
   while (head->next != NULL)
   {
      head = head->next;
   }
   return head;
}
node *groupedReverse(node *head, int k)
{

   if (!head)
   {
      return NULL;
   }
   node *next, *cur, *prev;
   int count = 0;
   cur = head;
   prev = next = NULL;
   next = head;
   while (next != NULL && count < k)
   {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      count++;
   }

   if (next != NULL)
   {
      // Recursively call the function again

      head->next = groupedReverse(next, k);
   }
   return prev;
}
node *create(int arr[], int n)
{
   node *a, *b, *c;
   a = new node;
   a->next = NULL;
   a->data = arr[0];
   c = a;
   for (int i = 1; i < n; i++)
   {
      b = new node;
      b->next = NULL;
      b->data = arr[i];
      c->next = b;
      c = b;
   }
   return a;
}
void printLL(node *head)
{
   while (head)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}

// // CPP program to reverse a linked list
// // in groups of given size
// #include <bits/stdc++.h>
// using namespace std;

// /* Link list node */
// class Node
// {
// public:
//    int data;
//    Node *next;
// };

// /* Reverses the linked list in groups
// of size k and returns the pointer
// to the new head node. */
// Node *reverse(Node *head, int k)
// {
//    // base case
//    if (!head)
//       return NULL;
//    Node *current = head;
//    Node *next = NULL;
//    Node *prev = NULL;
//    int count = 0;

//    /*reverse first k nodes of the linked list */
//    while (current != NULL && count < k)
//    {
//       next = current->next;
//       current->next = prev;
//       prev = current;
//       current = next;
//       count++;
//    }

//    /* next is now a pointer to (k+1)th node
//    Recursively call for the list starting from current.
//    And make rest of the list as next of first node */
//    if (next != NULL)
//       head->next = reverse(next, k);

//    /* prev is new head of the input list */
//    return prev;
// }

// /* UTILITY FUNCTIONS */
// /* Function to push a node */
// void push(Node **head_ref, int new_data)
// {
//    /* allocate node */
//    Node *new_node = new Node();

//    /* put in the data */
//    new_node->data = new_data;

//    /* link the old list off the new node */
//    new_node->next = (*head_ref);

//    /* move the head to point to the new node */
//    (*head_ref) = new_node;
// }

// /* Function to print linked list */
// void printList(Node *node)
// {
//    while (node != NULL)
//    {
//       cout << node->data << " ";
//       node = node->next;
//    }
// }

// /* Driver code*/
// int main()
// {
//    /* Start with the empty list */
//    Node *head = NULL;

//    /* Created Linked list
//    is 1->2->3->4->5->6->7->8->9 */
//    push(&head, 9);
//    push(&head, 8);
//    push(&head, 7);
//    push(&head, 6);
//    push(&head, 5);
//    push(&head, 4);
//    push(&head, 3);
//    push(&head, 2);
//    push(&head, 1);

//    cout << "Given linked list \n";
//    printList(head);
//    head = reverse(head, 3);

//    cout << "\nReversed Linked list \n";
//    printList(head);

//    return (0);
// }

// // This code is contributed by rathbhupendra
