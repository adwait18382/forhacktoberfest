#include<iostream>
using namespace std;
class matrix
{
private:
    int i,j,k,u,l,diga,a[3][3],b[3][3],sum[3][3],sub[3][3],mul[3][3],trans[3][3];
public:
    matrix()
    {
        u=0;
        l=0;
        diga=0;
    }
    void accept();
    void display();
    void add();
    void diff();
    void multiply();
    void transpose();
    void diagonal();
    void triangular();
};
void matrix::accept()
{
    cout<<"enter the elements of first matrix"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"enter the elements of second matrix"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cin>>b[i][j];
        }
    }
}
void matrix::display()
{
    cout<<" the first matrix is"<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"the second matrix is "<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void matrix::add()
{
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    cout<<"the addition matrix is "<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout<<sum[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void matrix::diff()
{
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            sub[i][j]=a[i][j]-b[i][j];
        }
    }
    cout<<"the subtraction matrix is "<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout<<sub[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void matrix::multiply()
{
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            mul[i][j]=0;
            for (k=0; k<3; k++)
            {
                mul[i][j]=mul[i][j]+(a[i][k]*b[k][j]);
            }

        }
    }
    cout<<"the multiplication matrix is "<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout<<mul[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void matrix::transpose()
{
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            trans[i][j]=a[j][i];
        }
    }

    cout<<"the transpose of first matrix is "<<endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout<<trans[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void matrix::triangular()
{
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i>j&&a[i][j]==0)
                u++;
            else if(i<j&&a[i][j]==0)
                l++;
        }
    }
    cout<<endl;
    if(u==3&&l==3)
        cout<<"the matrix is diagonal matrix"<<endl;
    else if(u==3)
        cout<<"first matrix is a upper triangular matrix"<<endl;
    else if(l==3)
        cout<<"first matrix is a lower triangular matrix"<<endl;
    else
        cout<<"first matrix is niether upper triangular nor lower triangular"<<endl;
}
void matrix::diagonal()
{
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i==j)
                diga=diga+a[i][j];

        }
    }
    cout<<"the sum of diagonal elements of first matrix is "<<diga<<endl;
}
int main()
{
    matrix m;
    int c;
    char x;
    m.accept();
    m.display();
    do
    {
        cout<<"enter the operation to be performed"<<endl;
        cout<<"1 for addition "<<endl;
        cout<<"2 for subtration "<<endl;
        cout<<"3 for multiplication"<<endl;
        cout<<"4 for transpose "<<endl;
        cout<<"5 for diagonal sum "<<endl;
        cout<<"6 to check for lower triangular or upper triangular "<<endl;
        cin>>c;
        switch(c)
        {
        case 1:
            m.add();
            break;
        case 2:
            m.diff();
            break;
        case 3:
            m.multiply();
            break;
        case 4:
            m.transpose();
            break;
        case 5:
            m.diagonal();
            break;
        case 6:
            m.triangular();
            break;
        default:
            cout<<"enter a valid choice"<<endl;
        }
        cout<<"would you like to continue(y/n) "<<endl;
        cin>>x;
    }
    while(x=='y');
    return 0;
}
