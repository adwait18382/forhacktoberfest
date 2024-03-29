/*This is final code
This code:
1.checks wether expression is well parantesized or not.
2.converts infix expression to postfix
3.evaluates the postfix expression to get the result

so in infix expression dont input variables,input numbers */

#include<iostream>
#include<stack>
#include<string>
#include<stdlib.h>

using namespace std;

bool ispair(char opening,char closing)
{
    if(opening=='('&&closing==')')
        return true;
    else if(opening=='['&&closing==']')
        return true;
    else if(opening=='{'&&closing=='}')
        return true;
    return false;

}

bool isvalid(string exp) //function to check paranthesis
{
    stack<char> s1;
    int length=exp.length();
    for(int i=0; i<length; i++)
    {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
            s1.push(exp[i]);
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
        {
            if(s1.empty()||!ispair(s1.top(),exp[i]))
                return false;
            else
                s1.pop();
        }
    }
    if(s1.empty())
        return true;
    else
        return false;
}


bool isoperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else
        return false;

}
bool isnumeric(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    //else
    return false;
}
bool isoperand(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    else if(c >= 'a' && c <= 'z')
        return true;
    else if(c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}
int getweight(char op)
{
    int weight;
    switch(op)
    {
    case'+':
        weight=1;
        break;
    case'-':
        weight=1;
        break;
    case'*':
        weight=2;
        break;
    case'/':
        weight=2;
        break;
    case'^':
        weight=3;
        break;
    }
    return weight;
}
int hashigherprecedence(char op1,char op2) //function to check precedence
{
    int op1weight=getweight(op1);
    int op2weight=getweight(op2);
    if(op1weight>=op2weight)
        return true;
    else
        return false;
}
string postfixEvalve;

string infixtopostfix(string infix)
{

    stack<char> s;
    string postfix;
    for(int i=0; i<infix.length(); i++)
    {
        if(infix[i]==' ')
            continue;

        else if(isoperator(infix[i]))
        {
            while(!s.empty()&&s.top()!='('&&hashigherprecedence(s.top(),infix[i]))
            {
                postfix=postfix+s.top();
                postfixEvalve=postfixEvalve+s.top(); //the next 3 lines of code including this is to create a postfix expression with spaces
                if(!isnumeric(infix[i+1]))
                    postfixEvalve=postfixEvalve+" ";
                s.pop();
            }
            s.push(infix[i]);
        }

        else if(isoperand(infix[i]))
        {
            postfix=postfix+infix[i];
            postfixEvalve=postfixEvalve+infix[i];
            if(!isnumeric(infix[i+1]))
                postfixEvalve=postfixEvalve+" ";
        }
        else if(infix[i]=='(')
            s.push(infix[i]);

        else if(infix[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                postfix=postfix+s.top();
                postfixEvalve=postfixEvalve+s.top();
                if(!isnumeric(infix[i+1]))
                    postfixEvalve=postfixEvalve+" ";
                s.pop();
            }
            s.pop();
        }

    }
    while(!s.empty())
    {
        postfix=postfix+s.top();
        postfixEvalve=postfixEvalve+s.top();
        //if(!isnumeric(expression[i+1])
        postfixEvalve=postfixEvalve+" ";
        s.pop();
    }

//cout<<"inside "<<postfixEvalve<<endl;
    return postfix;
}
int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+')
        return operand1 +operand2;
    else if(operation == '-')
        return operand1 - operand2;
    else if(operation == '*')
        return operand1 * operand2;
    else if(operation == '/')
        return operand1 / operand2;

    else cout<<"Unexpected Error \n";
    return -1;
}
int EvaluatePostfix(string expression) //function to evaluate postfix
{

    stack<int> s3;

    for(int i = 0; i< expression.length(); i++)
    {
        if(expression[i] == ' ' || expression[i] == ',')
            continue;
        else if(isoperator(expression[i]))
        {
            int operand2 = s3.top();
            s3.pop();
            int operand1 = s3.top();
            s3.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            s3.push(result);
        }
        else if(isnumeric(expression[i]))
        {
            int operand = 0;
            while(i<expression.length() && isnumeric(expression[i]))
            {
                operand = (operand*10) + (expression[i]-'0');
                i++;
            }
            i--;
            s3.push(operand);
        }
    }

    return s3.top();
}
bool isnumericstring()
{
    int i=-1;

    while(++i<postfixEvalve.length())
    {
        if(postfixEvalve[i]==' ')
            continue;
        if((postfixEvalve[i]>='a'&&postfixEvalve[i]<='z')||(postfixEvalve[i]>='A'&&postfixEvalve[i]<='Z'))
            return false;
    }
    return true;
}
int main()
{

    string expression,result;
    int output;
    do
    {
        cout<<"enter the infix expression ";
        getline(cin,expression);
        if(isvalid(expression))
        {
            result=infixtopostfix(expression);
            cout<<"the postfix expression is ";
            cout<<result<<endl;

            if(!isnumericstring())
            {
                cout<<"enter a numeric string to get evaluation "<<endl;
                break;
            }
            output=EvaluatePostfix(postfixEvalve);
            cout<<"the result is "<<output<<endl;
            break;

        }
        else
        {
            cout<<"expression is not well parenthesezid"<<endl;
            cout<<"please enter valid expression "<<endl;
        }
    }
    while(1);

    return 0;
}
