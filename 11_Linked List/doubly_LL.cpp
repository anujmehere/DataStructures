#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
};

//traverse a doubly linked list
void frnt_traverseDLL(Node *root)
{
    if(root==NULL)
        return;
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->next;
    }
}
void back_traverseDLL(Node *root)
{
    if(root==NULL)
        return;
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->prev;
    }
}

//Insert at the begining of a DLL
Node *insertBegin(Node *root,int val)
{
    Node *temp = new Node(val);
    temp->next=root;
    if(root!=NULL)
        root->prev=temp;
    return temp;
}

//Insert at the end of DLL
Node *insertEnd(Node *root,int val)
{
    Node *temp=new Node(val);
    if(root==NULL) return temp;
    Node *curr=root;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return root;
}

//Reverse a DLL
//10->20->30  => 30->20->10
Node *reverseDLL(Node *root)
{
    if(root==NULL) return NULL;
    if(root->next==NULL) return NULL;
    Node *prv=NULL;
    Node *curr=root;
    while(curr!=NULL)
    {
        prv=curr->prev;
        curr->prev=curr->next;
        curr->next=prv;
        curr=curr->prev;
    }
    return prv->prev;
}

//Delete head of a DLL
Node *deleteheadDLL(Node *root)
{
    if(root==NULL)return NULL;
    if(root->next==NULL) return NULL;
    root=root->next;
    root->prev=NULL;
    return root;
}

//Delete last node of a DLL
Node *deleteEndDLL(Node *root)
{
    if(root==NULL) 
        return NULL;
    if(root->next==NULL) 
    {
        delete root; 
        return NULL;
    }
    Node *curr=root;
    while(curr->next!=NULL)
    {   curr=curr->next;
        
    }
    curr->prev->next=NULL;
    delete curr;
    return root;
}
int main()
{
    //10 -> 20 -> 30 
    Node *head = new Node(10);
    Node *t1   = new Node(20);
    Node *t2   = new Node(30);
    Node *t3   = new Node(40);
    head->next = t1;
    t1->prev = head;
    t1->next = t2;
    t2->prev = t1;
    t2->next = t3;
    t3->prev = t2;
    
    frnt_traverseDLL(deleteEndDLL(head));
}
