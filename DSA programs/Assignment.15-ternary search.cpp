#include<iostream>
using namespace std;
int size;
void ternarysearch(int a[],int key)
{
    bool found=false;
    int beg,end,mid1,mid2;
    beg=0,end=size-1;


    while(beg<=end)
    {
        mid1=beg+(end-beg)/3;
        mid2=mid1+(end-beg)/3;

        if(a[mid1]==key||a[mid2]==key)
        {
            found=true;
            break;
        }
        else if(key<a[mid1])
            end=mid1-1;
        else if(key>a[mid2])
            beg=mid2+1;
        else
        {
            beg=mid1+1;
            end=mid2-1;
        }
    }
    if(found)
        cout<<"Roll no "<<key<<" has attended the trainning program"<<endl;
    else
        cout<<"Roll no "<<key<<" has not attended the trainning program"<<endl;

}
int main()
{
    int *a,key,index;
    cout<<"Enter the no of students who attended the trainning program "<<endl;
    cin>>size;
    a=new int[size];
    cout<<"enter their roll nos "<<endl;
    cout<<"enter in a sorted manner "<<endl;

    for(int i=0; i<size; i++)
        cin>>a[i];
    cout<<"enter the roll no of student you want to search for ";
    cin>>key;
    ternarysearch(a,key);

    return 0;
}
