#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int val;
    Node *next=NULL;
    Node(int d)
    {
        val=d;
        next=NULL;
    }
};

void traverse_CLL(Node *head)
{
    if(head==NULL) return;
    Node *curr=head;
    do
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }while(curr!=head);
}

//insert at begin of a circular linked list eg insert 5 at begin of CLL 10->15->20->25
//here we try to implement it using O(1) time
// we insert temp between head and its immediate next =>10->5->15->20->25
//we ue a new int and swap values of head and temp => 5->10->15->20->25
Node *insert_begCLL(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int t=head->val;
        head->val=temp->val;
        temp->val=t;
        return head;
    }
}

//insert at end of circular linked list
//insert at end is same as insert at begin just return head->next
Node *insert_endCLL(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int t=head->val;
        head->val=temp->val;
        temp->val=t;
        return head->next;
    }
}

//delete head of CLL
Node *del_headCLL(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        head->val=head->next->val;
        head->next=head->next->next;
        return head;
    }
}


//Delete kth element from a CLL
Node *delete_kCLL(Node *head,int k)
{
    if(head==NULL) return NULL;
    if(k==1) 
    {
        del_headCLL(head);
    }
    Node *curr=head;
    for(int i=0;i<k-2;i++)
    {
        curr=curr->next;
    }
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}



int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=head;
    //traverse_CLL(head);cout<<endl;
    traverse_CLL(del_headCLL(head));
}