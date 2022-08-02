#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
//Binary Tree
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
//Inorder Left Root Right
void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<(root->key)<<" ";
        inorder(root->right);
    }
}
//Preorder Root Left Right
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<(root->key)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//Postorder Left Root Right
void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<(root->key)<<" ";
    }
}

//Height of Binary Tree
int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return (max(height(root->left),height(root->right))+1);
    }
}

//Size of a Binary Tree
int size_tree(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return size_tree(root->left)+size_tree(root->right)+1;
    }
}
//Roots at a distance K from root
void printkdist(Node *root,int k)
{
    if(root==NULL){return;}
    if(k==0){cout<<(root->key)<<" ";}
    else
    {
        printkdist(root->left,k-1);
        printkdist(root->right,k-1);
    }
}

//Level Traversal of Binary Tree using queue (FIFO)
void levelprint(Node *root)
{
    if(root==NULL){return;}
    queue <Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *curr=q.front();
        q.pop();
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}

//Level Traversal Line by Line of Binary Tree using queue (FIFO)
void levelprintLine(Node *root)
{
    if(root==NULL){return;}
    queue <Node *>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}

//Maximum in a Binary Tree
int max_btree(Node *root)
{
    if(root==NULL)
    {return INT_MIN;}
    else
    {
        return max(root->key,max(max_btree(root->left),max_btree(root->right)));
    }
}

//Print left view of Binary tree
int maxlevel=0;
void printleft(Node *root,int level)
{
    if(root==NULL){return;}
    if(maxlevel<level)
    {
        cout<<(root->key)<<" ";
        maxlevel=level;
    }
    printleft(root->left,level+1);
    printleft(root->right,level+1);
}
void printleftView(Node *root)
{
    printleft(root,1);
}
//Binary Tree
//         20
//    10        30
//  5   15   25     40
int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right= new Node(30);
    root->right->right=new Node(40);
    root->right->left = new Node(25);
    root->left->left = new Node(5);
    root->left->right= new Node(15);
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // cout<<height(root);
    // cout<<endl;
    // printkdist(root,2);
    //levelprint(root);
    //levelprintLine(root);
    //cout<<size_tree(root);
    //cout<<max_btree(root);
    printleftView(root);
    return 0;
}
