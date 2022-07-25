#include<iostream>
#include<vector>
using namespace std;

//Declaring a Linked List Structure
struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val=x;
        next=NULL;
    }
};

//Traverse a singly Linked List function
void printLL(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}

//Recursive traversal of Linked List
void recprintLL(Node *head)
{
    if(head==NULL)
        return;
    else 
        cout<<head->val<<" ";
        recprintLL(head->next);
}

//Insert at the beginning of a Linked List
Node *insertbegLL(Node *head,int n)
{
    Node *temp =new Node(n);
    if(head==NULL)
        return temp;
    else
        temp->next=head;
        return temp;
}

//Insert at the end of a linked list
Node *insertendLL(Node *head,int n)
{
    Node *temp = new Node(n);
    if(head==NULL) return temp;
    Node *curr=head;
    while (curr->next=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;   
}

//Delete head node in a linked list
Node *deletehead(Node *head)
{
    if(head==NULL)
        return NULL;
    return head->next;
}

//Delete last node in a singly linked list
Node *deletelastnode(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL)    return NULL;
    Node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=NULL;
    return head;
}

//insert at given position in a linked list
Node *insertpos(Node *head,int pos,int data)
{
    Node *temp = new Node(data);
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    for(int i=1;i<=pos-2 && curr!=NULL ;i++)
    {
        curr=curr->next;
    }
    if(curr==NULL) return head;
    temp->next = curr->next;
    curr->next =temp;
    return head;
}

//Search in a linked list
int searchLL(Node *head,int x)
{
    if(head==NULL) return -1;
    if(head->val==x) return 1;
    else
    {
        int res=searchLL(head->next,x);
        if(res==-1) return res;
        else return res+1;
    }
}


//sorted insert in a singly LL
Node *sortedinsert(Node *root,int x)
{
    Node *temp=new Node(x);
    if(root==NULL) return temp;
    if(x<root->val)
    {
        temp->next=root;
        return temp;
    }
    Node *curr=root;
    while (curr->next->val<=x)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return root;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    recprintLL(sortedinsert(head,25));
}