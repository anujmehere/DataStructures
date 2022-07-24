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
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    recprintLL(deletelastnode(head));
}