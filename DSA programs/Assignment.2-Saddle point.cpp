#include<iostream>
using namespace std;

void saddle(int a[5][5],int row,int col);

int main()
{
int a[5][5],row,col;
cout<<"Enter no. of rows and columns: "<<endl;
cin>>row>>col;
saddle(a,row,col);
return 0;
}


void saddle(int a[5][5],int row,int col)
{


int i,j,min[3],max[3];
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
cin>>a[i][j];
}
}


cout<<"The matrix is: "<<endl;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}


for(i=0;i<row;i++)
{
min[i]=a[i][0];
for(j=1;j<col;j++)
{
if(min[i]>a[i][j])
{
min[i]=a[i][j];
}
}
}


for(j=0;j<col;j++)
{
max[j]=a[0][j];
for(i=1;i<row;i++)
{
if(max[j]<a[i][j])
{
max[j]=a[i][j];
}
}
}


int k=0;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
if(min[i]==max[j])
{
cout<<"Saddle point is: "<<min[i]<<endl;
k++;
}
}
}
if(k==0)
{
    cout<<"No saddle point"<<endl;
}

}































