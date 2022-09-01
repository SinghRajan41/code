#include<iostream>
#include<cstring>
using namespace std;
template<class X> class queue
{
    X *arr;
    int size,front,last;
    public:
    queue()
    {
        cout<<"Default size of the queue is 50";
        size=50;
        arr=new X[size];
        front=-1;
        last=-1;
    }
    queue(int n)
    {
        size=n;
        arr=new X[size];
        front=-1;
        last=-1;
    }
    ~queue()
    {
        delete []arr;
    }
    void enqueue(X value);
    void dequeue();
    int isempty();
    X peeklast();
    X peekfront();
    void display();
};
template<class X> void queue<X>::display()
{
    if(front==-1)
    {
        cout<<"Queue is empty\n";return;
    }
    for(int i=0;i<=last;i++)
    {
        cout<<arr[i]<<" ";
    }
}
template<class X> int queue<X>::isempty()
{
    if(last == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
template<class X> X queue<X>::peeklast()
{
    X obj;
    if(last == -1)
    {
        cout<<"The queue is already empty\nReturning Garbage Value\n";return obj;
    }
    else
    {
        obj=arr[last];
        return obj;
    }

}
template<class X> X queue<X>::peekfront()
{
    X obj;
    if(front == -1)
    {
        cout<<"The queue is already empty\nReturning Garbage Value\n";return obj;
    }
    obj = arr[front];
    return obj;
}
template<class X> void queue<X>::enqueue(X value)
{
    if(last == size-1)
    {
        cout<<"Queue is full\nReturning from Enqueue function\n";
        return;
    }
    if(front == -1)
    {
        front+=1;
    }
    last+=1;
    arr[last]=value;
}
template<class X> void queue<X>::dequeue()
{
    if(last == -1)
    {
        cout<<"Queue is already empty\nreturning from dequeue function\n";
        return;
    }
    else
    {
        if(last == 0)
        {
            last-=1;front=-1;
            return;
        }
        for(int i=1;i<=last;i++)
        {
            arr[i-1]=arr[i];
        }
        last-=1;
        
    }
}
int main()
{
  queue<float> q(30);
  for(int i=0;i<10;i++)
  {
    q.enqueue(2.111);
  }
  cout<<q.peeklast();
  return 0;
}