#include<iostream>
#include<string>
using namespace std;
template<class X> class queue
{
     class stack
    {
        X *arr;
        int top,size;
        public:
        stack()
        {
            size =100;
            arr=new X[100];
            top=-1;
        }
        void push(X value)
        {
            if(top == size-1)
            {
                cout<<"\nStack is full\n Returning from push function\n";
                return;
            }
            else
            {
                top+=1;
                arr[top]=value;
            }
        }
        X pop()
        {
            X value;
            if(top <=-1)
            {
                cout<<"\nThe Stack is already\nReturning garbage values\n";
                
                return value;
            }
            else
            {
               value=arr[top];
               top-=1;
               return value;
            }
        }
        int isempty()
        {
            if(top <= -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int isfull()
        {
            if(top == size-1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        void displayfromtop()
        {
            for(int i=top;i>-1;i--)
            {
                cout<<arr[i]<<" ";
            }
        }
        void displayfrombottom()
        {
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    };
    stack s1,s2;
    public:
    void nq(X value)
    {
        if(s1.isfull())
        {
            cout<<"The queue is full\n";
            return ;
        }
        else
        {
            s1.push(value);
        }
    }

    void dq()
    {
        if(s1.isempty() && s2.isempty())
        {
            cout<<"\nThe queue is empty\n";
            return;
        }
        else if(s2.isempty() && !s1.isempty())
        {
            while(!s1.isempty())
            {
                s2.push(s1.pop());
            }
            s2.pop();
        }
        else
        {
            s2.pop();
        }
    }
    void display()
    {
        if(s1.isempty() && s2.isempty())
        {
            cout<<"\nThe queue is empty\nReturning from Display function\n";
            return;
        }
        else
        {
            s2.displayfromtop();
            s1.displayfrombottom();
        }
    }
};
int main()
{
queue<const char *> q;
for(int i=0;i<105;i++)
{
    q.nq("Hello");
}

q.display();
return 0;
}
