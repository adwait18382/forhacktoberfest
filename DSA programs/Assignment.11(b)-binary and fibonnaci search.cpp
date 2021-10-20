#include<iostream>
using namespace std;
int size;
class program
{
    int *a,key;
    bool found;
public:
    program()
    {
        cout<<"enter the number of students who attended the traning program ";
        cin>>size;
        a=new int[size];
    }
    void getdata();
    void binarysearch();
    void fibonaccisearch(int,int);

};
void program::getdata()
{
    cout<<"\nenter their roll nos "<<endl;
    cout<<"Please enter in a sorted manner "<<endl;
    for(int i=0; i<size; i++)
        cin>>a[i];
}
void program::binarysearch()
{
    found=false;
    int beg=0,end=size-1,mid=(beg+end)/2;
    cout<<"enter the element you want to search for ";
    cin>>key;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(a[mid]==key)
        {
            found=true;
            break ;
        }
        else if(a[mid]<key)
            beg=mid+1;
        else
            end=mid-1;
    }

    if(found)
        cout<<"\nroll no "<<key<<" has attented the training program"<<endl;
    else
        cout<<"\nroll no "<<key<<" has not attented the training program"<<endl;
}



int lesser(int a, int b){
    if(a < b)
        return a;
    else
    return b;
}

void program::fibonaccisearch(int x, int length)
{
    int fib1 = 1;
    int fib2 = 0;
    int fibs = fib1 + fib2;

    while(fibs < length){
        fib2 = fib1;
        fib1 = fibs;
        fibs = fib2 + fib1;
    }

    int offset = -1;

    while(fibs > 1)
    {
        int i = lesser(offset + fib2, length - 1);

        if(a[i] < x){
            fibs = fib1;
            fib1 = fib2;
            fib2 = fibs - fib1;
            offset = i;
        }
        else if(a[i] > x){
            fibs = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibs - fib1;
        }
        else{
            cout<<"No. found at location "<<i+1<<endl;
            return;
        }
    }
    if(fib1 && a[offset + 1] == x){
        cout<<"No. found at location "<<offset + 1<<endl;
        return;
    }

    cout<<"No. not found"<<endl;
}

int main()
{
    int key;
    char c;
    program p;
    p.getdata();
    cout<<"\nSelect one of the searching techniques "<<endl;
    cout<<"1.Binary Search "<<endl;
    cout<<"2.Fibonacci search"<<endl;
    cin>>c;
    switch(c)
    {
    case '1':
        p.binarysearch();
        break;
    case '2':
        cout<<"Enter the no you want to search for "<<endl;
        cin>>key;
        p.fibonaccisearch(key,size);
        break;
    default:
        cout<<"enter a valid choice "<<endl;
    }

    return 0;

}
