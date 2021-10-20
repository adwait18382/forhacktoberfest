#include<iostream>
using namespace std;

struct node
{
    long long int prn;
    string name;
    node *next;
};
class club
{
    node *head;
    long long int p;
    string nam;

public:
    static int no;
    club()
    {
        head=NULL;
    }
    node* getHead()
    {
        return head;
    }
    void createclub();
    void addmember();
    void display();
    void deletepresident();
    void deletesecretry();
    void displayreverse(node *);
    void deletemember(long long int);
};
int club::no=0;
void club::createclub()
{
    node *temp,*n;
    if(head==NULL)
    {
        cout<<"\nenter the details of president "<<endl;
        cout<<"Name: ";
        cin>>nam;
        do
        {
            cout<<"PRN no: ";
            cin>>p;
            if(p<0)
                cout<<"PRN cant be negative,please enter positive  ";
            else
                break;
        }
        while(1);
        temp=new node;
        temp->name=nam;
        temp->prn=p;
        temp->next=NULL;
        head=temp;
        club::no++;
    }
    cout<<"\nenter the details of secreatery "<<endl;
    cout<<"Name: ";
    cin>>nam;
    do
    {
        cout<<"PRN no: ";
        cin>>p;
        if(p<0)
            cout<<"PRN cant be negative,please enter positive  ";
        else
            break;
    }
    while(1);
    n=new node;
    n->name=nam;
    n->prn=p;
    temp->next=n;
    n->next=NULL;
    club::no++;
}
void club::addmember()
{
    int i=0;
    node *n;
    node *temp=head;
    while(i++<club::no-2)
    {
        temp=temp->next;
    }
    cout<<"\nenter the details of member "<<endl;
    cout<<"Name: ";
    cin>>nam;
    do
    {
        cout<<"PRN no: ";
        cin>>p;
        if(p<0)
            cout<<"PRN cant be negative,please enter positive  ";
        else
            break;
    }
    while(1);
    n=new node;
    n->name=nam;
    n->prn=p;
    n->next=temp->next;
    temp->next=n;
    club::no++;

}
void club::display()
{
    if(head==NULL)
    {
        cout<<"Club is empty,Add some members in the club first "<<endl;
    }
    int i=0;
    node *temp=head;
    cout<<"\nthe details of president are: "<<endl;
    cout<<"Name: "<<temp->name<<endl;
    cout<<"PRN no: "<<temp->prn<<endl;
    temp=temp->next;
    while(i++<club::no-2)
    {
        cout<<"\nthe details of member "<<i<<" are: "<<endl;
        cout<<"Name: "<<temp->name<<endl;
        cout<<"PRN no: "<<temp->prn<<endl;
        temp=temp->next;
    }
    if(club::no>1)
    {
        cout<<"\nthe details of secreatry are: "<<endl;
        cout<<"Name: "<<temp->name<<endl;
        cout<<"PRN no: "<<temp->prn<<endl;
    }
}
void club::deletepresident()
{

    node *temp=head;
    head=head->next;
    delete temp;
    club::no--;
}
void club::deletesecretry()
{
    node *temp=head;
    int i=0;
    while(i++<club::no-2)
    {
        temp=temp->next;
    }
    temp->next=NULL;

    club::no--;
}
void club::displayreverse(node *temp)
{
    if(temp==NULL)
        return;
    displayreverse(temp->next);
    cout<<"\n\nName: "<<temp->name;
    cout<<"\nPRN no: "<<temp->prn;

}
void club::deletemember(long long int PRN)
{
    int i=0;
    node*temp=head;
    if(temp->prn==PRN)
    {
        deletepresident();
        return;
    }
    while(i++<club::no-1)
    {
        if(temp->next->prn==PRN)
        {
            temp->next=temp->next->next;
            club::no--;
            return;
        }
        temp=temp->next;
    }
    cout<<"PRN no doesnt exsist "<<endl;
}
int main()
{
    long long int PRN;
    int n;
    club c;
    char x;
    do
    {
        cout<<"\n\nEnter one of the following operations "<<endl;
        cout<<"1.To create a club "<<endl;
        cout<<"2.To add a member "<<endl;
        cout<<"3.To display the no of members in the club "<<endl;
        cout<<"4.To display all the members in the club "<<endl;
        cout<<"5.To delete the president "<<endl;
        cout<<"6.To delete the secreatry of club "<<endl;
        cout<<"7.to delete a member "<<endl;
        cout<<"8.to display list in reverse order "<<endl;
        cout<<"q.Quit "<<endl;
        cin>>x;
        switch(x)
        {
        case '1':
            c.createclub();
            cout<<"enter the no of members you want to add in the club "<<endl;
            cin>>n;
            for(int i=0; i<n; i++)
                c.addmember();
            break;
        case '2':
            cout<<"enter the no of members you want to add in the club "<<endl;
            cin>>n;
            for(int i=0; i<n; i++)
                c.addmember();
            break;
        case '3':
            cout<<"There are "<<club::no<<" members in club "<<endl;
            break;
        case '4':
            c.display();
            break;
        case '5':
            c.deletepresident();
            break;
        case '6':
            c.deletesecretry();
            break;
        case '7':
            cout<<"enter the PRN no of member to be deleted: ";
            cin>>PRN;
            c.deletemember(PRN);
            break;
        case '8':
            c.displayreverse(c.getHead());
            break;

        case 'q':
            break;

        default:
            cout<<"Enter a valid choice"<<endl;
        }
    }
    while(x!='q');

    return 0;
}
