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

//Now Lets try to generate stack using vectors
struct VecStack
{
    vector<int> v;
    void push(int x)
    {
        v.push_back(x);
    }
    int pop()
    {
        int res=v.back();
        v.pop_back();
        return res;
    }
    int peek()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool isEmpty()
    {
        return v.empty();
    }
};

//Linked List Implementation of Stack 
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
struct LLStack
{
    Node *head;
    int sz;
    LLStack()
    {
        head=NULL;
        sz=0;
    }
    void push(int x)
    {
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    int pop()
    {
        if(head==NULL)
            return INT_MAX;
        int res=head->data;
        Node *temp=head;
        head=head->next;
        delete temp;
        sz--;
        return res;
    }
    int peek()
    {
        if(head==NULL)
            return INT_MAX;
        return head->data;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return (head==NULL);
    }

};

int main()
{
    LLStack s;
    //VecStack s;
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