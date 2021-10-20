#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class List
{
private:
    int value;
    node *h[2],*po,*ne,*merge;
public:
    List()
    {
        po=NULL;
        ne=NULL;
        merge=NULL;
        for(int i=0; i<2; i++)
            h[i]=NULL;
    }
    void create(int);
    void display(int);
    void insertnode(int);
    void deletenegative(int);
    void segregate(int);
    void mergelist(int,int);
};





void List::create(int listno)
{
    node *head=h[listno];
    node *temp,*n;
    cout<<"\nEnter the data to be stored: ";
    cin>>value;
    if(head==NULL)
    {
        n=new node;
        n->data=value;
        n->next=NULL;
        head=n;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        n=new node;
        n->data=value;
        n->next=NULL;
        temp->next=n;
    }
    h[listno]=head;
}




void List::display(int listno)
{
    int i=1;
    node *temp=h[listno];

    while(temp!=NULL)
    {
        cout<<"Data at node "<<i++<<" is "<<temp->data<<endl;
        temp=temp->next;
    }
}



void List::insertnode(int listno)
{
    int loc;
    int i=0;
    node *head,*temp,*n;
    head=h[listno];
    cout<<"enter the location at which you want to insert a node "<<endl;
    cin>>loc;
    cout<<"enter the data at node "<<endl;
    cin>>value;
    temp=head;
    while(i!=loc-2)
    {
        temp=temp->next;
        i++;
    }
    n=new node;
    n->data=value;
    n->next=temp->next;
    temp->next=n;

    h[listno]=head;
}




void List::deletenegative(int listno)
{
    node *head=h[listno];
    node *temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data < 0)
        {
            temp = temp->next;
            head = head->next;
        }
        else if(temp->next->data < 0)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }

    }

    h[listno]=head;
}






void displaylist(node* temp)
{
    int i=1;
    if(temp==NULL)
        cout<<"No such elements "<<endl;
    else
    {
        while(temp!=NULL)
        {
            cout<<"The data at node "<<i++<<" : "<<temp->data<<endl;
            temp=temp->next;
        }
    }
}





void List::segregate(int listno)
{
    node *head=h[listno];
    node *temp,*tempp,*tempn,*n;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data>=0)
        {
            if(po==NULL)
            {
                n=new node;
                n->data=temp->data;
                n->next=NULL;
                po=n;
            }
            else
            {
                tempp=po;
                while(tempp->next!=NULL)
                    tempp=tempp->next;

                n=new node;
                n->data=temp->data;
                n->next=NULL;
                tempp->next=n;
            }

        }
        else
        {
            if(ne==NULL)
            {

                n=new node;
                n->data=temp->data;
                n->next=NULL;
                ne=n;
            }
            else
            {
                tempn=ne;
                while(tempn->next!=NULL)
                    tempn=tempn->next;

                n=new node;
                n->data=temp->data;
                n->next=NULL;
                tempn->next=n;
            }
        }

        temp=temp->next;
    }

    cout<<"\nThe positive elements are: "<<endl;
    displaylist(po);
    cout<<"\nThe negative elements are: "<<endl;
    displaylist(ne);

}





void sortlist(node *head)
{
    node *temp;
    node *temps;
    temp=head;
    int length=1;
    while(temp->next!=NULL)
    {
        length++;
        temp=temp->next;
    }
    while(length!=0)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data>temp->next->data)
            {
                temps=new node;
                temps->data=temp->next->data;
                temp->next->data=temp->data;
                temp->data=temps->data;
            }
            temp=temp->next;
        }
        length--;
    }
}





void List::mergelist(int listno1,int listno2)
{
    node *head1=h[listno1];
    node *head2=h[listno2];
    node *temp,*n,*tempm;

    temp=head1;
    while(temp!=NULL)
    {
        if(merge==NULL)
        {
            n=new node;
            n->data=temp->data;
            n->next=NULL;
            merge=n;
        }
        else
        {
            tempm=merge;
            while(tempm->next!=NULL)
                tempm=tempm->next;

            n=new node;
            n->data=temp->data;
            n->next=NULL;
            tempm->next=n;
        }
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL)
    {
        tempm=merge;
        while(tempm->next!=NULL)
            tempm=tempm->next;

        n=new node;
        n->data=temp->data;
        n->next=NULL;
        tempm->next=n;

        temp=temp->next;
    }
    sortlist(merge);
    cout<<"the merged list is "<<endl;
    displaylist(merge);
}





int main()
{
    List l;
    int n;
    int listno,listno1,listno2;
    char c;
    do
    {
        cout<<"\nEnter one of the following operations "<<endl;
        cout<<"1.To create a linked list "<<endl;
        cout<<"2.To display a linked list "<<endl;
        cout<<"3.To insert a number "<<endl;
        cout<<"4.To delete negative numbers "<<endl;
        cout<<"5.To segregate into positive and negative numbers "<<endl;
        cout<<"6.To merge 2 lists "<<endl;
        cout<<"q.Quit "<<endl;
        cin>>c;
        switch(c)
        {
        case '1':
            cout<<"enter the list no to be created ";
            cin>>listno;
            cout<<"enter the no of nodes to be formed ";
            cin>>n;
            for(int i=0; i<n; i++)
                l.create(listno);
            break;
        case '2':
            cout<<"enter the list no to be displayed ";
            cin>>listno;
            l.display(listno);
            break;
        case '3':
            cout<<"enter the list no to be modified ";
            cin>>listno;
            l.insertnode(listno);
            break;
        case '4':
            cout<<"enter the list no to be modified ";
            cin>>listno;
            l.deletenegative(listno);
            break;
        case '5':
            cout<<"enter the list no to be modified ";
            cin>>listno;
            l.segregate(listno);
            break;
        case '6':
            cout<<"enter the list nos to be merged ";
            cin>>listno1;
            cin>>listno2;
            l.mergelist(listno1,listno2);
            break;
        case 'q':
            break;

        default:
            cout<<"enter a valid choice "<<endl;

        }
    }
    while(c!='q' || c!='Q');

    return 0;
}
