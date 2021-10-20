#include<iostream>
using namespace std;
int size;
class student
{
    float *a;
public:
    student()
    {
        cout<<"enter the no of students in the class ";
        cin>>size;
        a=new float[size];
    }
    void getdata();
    int partition(int,int);
    void quicksort(int,int);
    void display();
};
void student::getdata()
{
    cout<<"\nenter their percentages "<<endl;
    for(int i=0; i<size; i++)
        cin>>a[i];
}
int student::partition(int start,int end)
{
    int pivot=a[end];
    int partitionindex=start;
    for(int i=start; i<end; i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[partitionindex]);
            partitionindex++;
        }
    }
    swap(a[partitionindex],a[end]);
    return partitionindex;
}

void student::quicksort(int start,int end)
{
    int pindex;
    if(start<end)
    {
        pindex=partition(start,end);
        quicksort(start,pindex-1);
        quicksort(pindex+1,end);
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
    student s;
    s.getdata();
    s.quicksort(0,size-1);
    s.display();
    return 0;

}
