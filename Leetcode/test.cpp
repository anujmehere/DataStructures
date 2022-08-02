#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next=NULL;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
void deleteNode(struct Node *head, int key)
{
    if(head==NULL)return;
    Node *curr=head;
    Node *prev;
    
    
}

int main()
{
    Node *head =new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next=head;

}