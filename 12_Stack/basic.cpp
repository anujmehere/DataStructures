#include<iostream>
#include<vector>
using namespace std;

struct Stack
{
    int cap;
    int top;
    int *arr;
    Stack(int c)
    {
        cap=c;
        arr=new int(cap);
        top=-1;
    }
    void push(int x)
    {
        top++;
        arr[top]=x;
    }
    int pop()
    {
        int res=arr[top];
        top--;
        return res;
    }
    int peek()
    {
        return arr[top];
    }
    int size()
    {
        return top+1;
    }
    bool isEmpty()
    {
        return (top==-1);
    }
};

//Now Lets try to

int main()
{
    Stack s(5);
    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}