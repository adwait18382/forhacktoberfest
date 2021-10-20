#include<iostream>
using namespace std;
int size;
class student
{
    float *a;
    float temp;
public:
    student()
    {
        cout<<"enter the no of students in the class ";
        cin>>size;
        a=new float[size];
    }
    void getdata();
    void bubblesort();
    void selectionsort();
    void display();
};
void student::getdata()
{
    cout<<"\nenter their percentages "<<endl;
    for(int i=0; i<size; i++)
        cin>>a[i];
}
void student::bubblesort()
{
    for(int j=0; j<size-1; j++)
    {
        for(int i=0; i<size; i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }

    }
}
void student::selectionsort()
{
    int min;
    for(int i=0; i<size-1; i++)
    {
        min=i;
        for(int j=i+1; j<size; j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }

}
void student::display()
{
    cout<<"\nthe top 5 scores are "<<endl;
    for(int i=size-1; i>size-6; i--)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    char c;
    student s;
    s.getdata();
    cout<<"\nSelect one of the sorting techniques "<<endl;
    cout<<"1.Bubble sort "<<endl;
    cout<<"2.Selection sort "<<endl;
    cin>>c;
    switch(c)
    {
    case '1':
        s.bubblesort();
        s.display();
        break;
    case '2':
        s.selectionsort();
        s.display();
        break;
    default:
        cout<<"enter a valid choice "<<endl;
    }

    return 0;

}
