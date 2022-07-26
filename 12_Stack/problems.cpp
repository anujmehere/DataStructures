#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

//Check for balanced paranthesis in a string
bool matching(char a,char b)
{
    cout<<a<<b<<endl;
    return (a=='(' && b==')')||(a=='{' && b=='}')||(a=='[' && b==']');
}
bool bal_paran(string str)
{
    stack <int> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else
        {
            if(s.empty()==false)
            {
                return false;
            }
            else if(matching(s.top(),str[i])==false)
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return (s.empty()==true);
}


//Implement two stacks in an array
struct TwoStack
{
    int *arr,cap,top1,top2;
    TwoStack(int n){ cap=n; top1=-1;top2=cap; arr=new int[n];}
    void push1(int x)
    {if(top1<top2-1){top1++;arr[top1]=x;}}
    void push2(int x)
    {if(top1<top2-1){top2--;arr[top2]=x;}}
    int pop1()
    {
        if(top1>=0)
        {   int b=arr[top1]; top1--; return b;}
        else
        {   exit(1);    }
    }
    int pop2()
    {
        if(top2<cap-1)
        {   int b=arr[top2];top2++; return b;}
        else
        {   exit(1);}
    }
};
int main()
{
    string s1="[{}]";
    cout<<bal_paran(s1);
    
}