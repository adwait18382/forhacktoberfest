#include<iostream>
using namespace std;
//#define MAX_SIZE 5

class Queue
{
    int MAX_SIZE;
    int *A;
    int front;
    int rear;

public:
    Queue()
    {
        cout<<"enter the size of queue "<<endl;
        cin>>MAX_SIZE;
        A=new int[MAX_SIZE];
        front=-1;
        rear=-1;
    }

    bool isfull()
    {
        if(rear==MAX_SIZE-1)
            return true;

        return false;
    }

    void enqueue(int x)
    {
        /*if(isfull())
        {
            cout<<"queue is full,cannot enqueue "<<endl;
            return;
        }*/
        if(isempty())
        {
            front=0;
            rear=0;
            A[rear]=x;
        }
        else
        {
            A[++rear]=x;
        }
    }

    void dequeue()
    {
        if(isempty())
        {
            cout<<"queue is already empty,cannot dequeue "<<endl;
            return;
        }
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front++;
    }

   // int top()
    //{
      //  return A[front];
    //}

    bool isempty()
    {
        if(front==-1&&rear==-1)
            return true;
        return false;
    }

    void print()
    {
        if(isempty())
        {
            cout<<"queue is empty "<<endl;
            return;
        }
        else
        {
            for(int i=front; i<=rear; i++)
                cout<<A[i]<<" ";
            cout<<endl;
        }
    }

};
int main()
{
    Queue q;
    int x;
    char c;
    do
    {
        cout<<"\nenter one of the following choices "<<endl;
        cout<<"1.enqueue"<<endl;
        cout<<"2.dequeue"<<endl;
        cout<<"3.print queue"<<endl;
        cout<<"q.Quit"<<endl;
        cin>>c;
        switch(c)
        {
        case '1':
            if(q.isfull())
            {
                cout<<"queue is full,cannot enqueue "<<endl;
                break;
            }
            cout<<"enter the no to be queued "<<endl;
            cin>>x;
            q.enqueue(x);
            break;
        case '2':
            q.dequeue();
            break;

        case '3':
            cout<<"queue : ";
            q.print();
            break;
        case 'q':
            break;
        default:
            cout<<"enter a valid choice "<<endl;
        }
    }
    while(c!='q');
    return 0;
}
