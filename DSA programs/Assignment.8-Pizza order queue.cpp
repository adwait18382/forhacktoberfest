#include<iostream>
using namespace std;
//#define MAX_SIZE 5

class Queue
{
    int *A;
    int MAX_SIZE;
    int front;
    int rear;

public:
    Queue()
    {
        cout<<"enter the size of the array "<<endl;
        cin>>MAX_SIZE;
        A=new int[MAX_SIZE];
        front=-1;
        rear=-1;
    }
    bool isfull()
    {
        if((rear+1)%MAX_SIZE==front)
            return true;

        return false;
    }
    void enqueue(int x)
    {

        if(isempty())
        {
            front=0;
            rear=0;
            A[rear]=x;
        }
        else
        {
            rear=(rear+1)%MAX_SIZE;
            A[rear]=x;
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
            front=(front+1)%MAX_SIZE;
    }
    int top()
    {
        return A[front];
    }
    bool isempty()
    {
        if(front==-1&&rear==-1)
            return true;

        return false;
    }
    void print()
    {
        cout<<"\nQueue: ";
        int count=(rear+MAX_SIZE-front)%MAX_SIZE+1;
        for(int i=0; i<count; i++)
        {
            int index = (front+i) % MAX_SIZE;
            cout<<A[index]<<" ";
        }
        cout<<endl;
    }
};
int main()
{

    Queue q;
    char c;
    int data;
    do
    {
        cout<<"\nEnter one of the following options "<<endl;
        cout<<"1.Enqueue "<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.To display front of queue"<<endl;
        cout<<"4.Display all elements of queue"<<endl;
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
            cout<<"enter the number to be enqueued: ";
            cin>>data;
            q.enqueue(data);
            break;
        case '2':
            q.dequeue();
            break;
        case '3':
            if(q.isempty())
            {
                cout<<"queue is empty "<<endl;
                break;
            }
            cout<<"\nthe element at front is: "<<q.top()<<endl;
            break;

        case '4':
            if(q.isempty())
            {
                cout<<"queue is empty "<<endl;
                break;
            }
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
