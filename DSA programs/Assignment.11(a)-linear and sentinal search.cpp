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
    void linearsearch();
    void sentinalsearch();

};
void program::getdata()
{
    cout<<"\nenter their roll nos "<<endl;
    for(int i=0; i<size; i++)
        cin>>a[i];
}
void program::linearsearch()
{
    int i;
    found=false;
    cout<<"enter the roll no of student you want to search for ";
    cin>>key;
    for(i=0; i<size; i++)
    {
        if(key==a[i])
        {
            found=true;
            break;
        }
    }
    if(found)
        cout<<"\nroll no "<<key<<" has attented the training program"<<endl;
    else
        cout<<"\nroll no "<<key<<" has not attented the training program"<<endl;
}
void program::sentinalsearch()
{
    int i=0,last;
    cout<<"enter the roll no of student you want to search for ";
    cin>>key;
    last=a[size-1];
    a[size-1]=key;
    while(a[i]!=key)
    {
        i++;
    }
    a[size-1]=last;

    if(i<size-1||a[size-1]==key)
        cout<<"\nroll no "<<key<<" has attented the training program"<<endl;
    else
        cout<<"\nroll no "<<key<<" has not attented the training program"<<endl;

}

int main()
{
    char c;
    program p;
    p.getdata();
    cout<<"\nSelect one of the searching techniques "<<endl;
    cout<<"1.Linear Search "<<endl;
    cout<<"2.Sentinal search"<<endl;
    cin>>c;
    switch(c)
    {
    case '1':
        p.linearsearch();
        break;
    case '2':
        p.sentinalsearch();
        break;
    default:
        cout<<"enter a valid choice "<<endl;
    }

    return 0;

}
