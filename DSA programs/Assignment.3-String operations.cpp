#include<iostream>
using namespace std;
class stringg
{
    char *str;
public:
    stringg()
    {
        str=new char[50];
    }
    void accept();
    void display();
    int length();
    int length(stringg);
    friend void join_string(stringg,stringg);
    bool compare(stringg);
    void copystring(stringg);
    friend stringg reversestring(stringg);
    void reverses(int);
    friend bool palindrome(stringg);
    friend void substring(stringg,stringg);
};
void stringg::accept()
{
    cin>>str;
}
void stringg::display()
{
    cout<<str<<endl;
}
int stringg::length()
{
    int len=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        len++;
    }
    //cout<<"the length of the string is "<<len<<endl;
    return len;
}
/*int stringg::length(stringg x)
{
    int len=0;
    for(int i=0; x.str[i]!='\0'; i++)
    {
        len++;
    }
    //cout<<"the length of the string is "<<len<<endl;
    return len;
}*/
void join_string(stringg x,stringg y)
{
    int k;
    stringg z;
    x.copystring(z);
    //cout<<z.str<<endl;
    //cout<<x.str<<endl;
    int len1,len2;
    len1=z.length();
    len2=y.length();
    for(k=len1; k<len1+len2; k++)
        z.str[k]=y.str[k-len1];
    z.str[k]='\0';
    cout<<" the concatenated string is "<<z.str<<endl;
    //cout<<x.str;
}
bool stringg::compare(stringg a)
{
    if(length()==a.length())
    {
        for(int i=0; str[i]!='\0'; i++)
        {
            if(str[i]!=a.str[i])
            {
                return  false;
                break;
            }
        }
        return true;
    }
    else if(length()>a.length())
        return false;
    else if(length()<a.length())
        return false;
}
void stringg::copystring(stringg z)
{
    int i=0;
    for(i=0; str[i]!='\0'; i++)
    {
        z.str[i]=str[i];

    }
    z.str[i]='\0';
}
void stringg::reverses(int i=0)
{
    // str=str+1;
    if (i!=length())
    {
        reverses(i+1);

    }
    cout<<str[i];
}
stringg reversestring(stringg x)
{
    stringg z;
    int i;
    int len1=x.length();
    for(i=0; i<len1; i++)
    {
        z.str[i]=x.str[len1-i-1];
    }
    z.str[i]='\0';
    //cout<<z.str<<endl;
    return z;
}

bool palindrome(stringg x)
{
    int i=0;
    stringg z;
    z=reversestring(x);
    while(i<x.length())
    {
        if(x.str[i]!=z.str[i])
            return false;
        i++;
    }
    return true;
}
void substring(stringg a,stringg b)
{
    bool sub=true;
    bool found=false;
    int len1=a.length();
    int len2=b.length();
    int i,j;

    for(i=0; i<len1; i++)
    {
        for(j=0; j<len2; j++)
        {
            sub=true;
            if(b.str[j]!=a.str[i+j])
            {
                sub=false;
                break;
            }
        }
        if(sub)
        {
            found=true;
            cout<<"Found at position "<<i+1<<endl;
        }
    }
    if(!found)
        cout<<"Not found "<<endl;

}
int main()
{
    char x;
    int l;
    stringg s1,s2,s3,s4;
    cout<<"enter the first string "<<endl;
    s1.accept();
    cout<<"enter the second string "<<endl;
    s2.accept();
    do
    {
        cout<<" \nSelect one of the following operations "<<endl;
        cout<<" 1.display a string "<<endl;
        cout<<" 2.calculate length of string "<<endl;
        cout<<" 3.concat 2 string"<<endl;
        cout<<" 4.compare 2 strings "<<endl;
        cout<<" 5.copy string "<<endl;
        cout<<" 6.reverse a string "<<endl;
        cout<<" 7.palindrome or not "<<endl;
        cout<<" 8.to find wether substring or not "<<endl;
        cout<<" q.Quit "<<endl;
        cin>>x;
        switch(x)
        {
        case '1':
            cout<<" the first string is  ";
            s1.display();
            cout<<" the second string is ";
            s2.display();
            break;
        case '2':
            l=s1.length();
            cout<<"the length of first string is "<<l<<endl;
            break;
        case '3':
            join_string(s1,s2);
            break;
        case '4':
            if(s1.compare(s2))
                cout<<"the strings are equal"<<endl;
            else
                cout<<"the strings are not equal"<<endl;
            break;
        case '5':
            s1.copystring(s3);
            cout<<"the copied string is ";
            s3.display();
            break;
        case '6'://s4=reversestring(s1);
            cout<<"the reverse of string is ";
            s1.reverses();
            cout<<endl;
            //s4.display();
            break;
        case '7':
            if(palindrome(s1))
                cout<<" the string is palindrome "<<endl;
            else
                cout<<"the string is not palindrome "<<endl;
            break;
        case '8':
            substring(s1,s2);
            break;
        case 'q':
            break;
        default:
            cout<<" enter a valid choice "<<endl;
            break;
        }

    }
    while(x!='q');
    return 0;
}


