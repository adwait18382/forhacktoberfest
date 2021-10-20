#include<iostream>
#include<stack>
#include<string>
using namespace std;

class expression
{
    string exp;
public:
    void getstring()
    {
        cout<<"enter the expression"<<endl;
        getline(cin,exp);
    }


bool ispair(char opening,char closing)
{
    if(opening=='(' && closing==')')
        return true;
    else if(opening=='[' && closing==']')
        return true;
    else if(opening=='{' && closing=='}')
        return true;
    else
        return false;

}

bool isvalid()
{
    stack<char> s;
    int length=exp.length();
    for(int i=0;i<length;i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            s.push(exp[i]);
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(s.empty() || !ispair(s.top(),exp[i]))
                return false;
            else
                s.pop();
        }


    }
    if(s.empty())
        return true;
    else
        return false;
}

};


int main()
{
    expression e;
    e.getstring();
    if(e.isvalid())
        cout<<"expression is well parenthesezid"<<endl;
    else
       cout<<"expression is not parenthesezid"<<endl;
       return 0;
}
