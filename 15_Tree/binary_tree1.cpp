#include<iostream>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
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

//16. Children Sum Property
bool child_sum(Node *root)
{
    if(root==NULL){return true;}
    if(root->left==NULL && root->right==NULL){return true;}
    int sum=0;
    if(root->left!=NULL){sum+=child_sum(root->left);}
    if(root->right!=NULL){sum+=child_sum(root->right);}
    return root->key==sum && child_sum(root->left) && child_sum(root->right);
}

//17. Check Height Balanced Trees i.e. difference between hight of left and right subtree shud not be greater than 1
//Tree is balanced for o/p =0,positive. Positive value is the height of tree. If o/p is -1 tree is not balanced.
int isBalanced(Node *root)
{
    if(root==NULL){return 0;}
    int lh=isBalanced(root->left);
    if(lh==-1){return -1;}
    int rh=isBalanced(root->right);
    if(rh==-1){return -1;}
    if(abs(lh-rh)>1)return -1;
    else
    {
        return max(lh,rh)+1;
    }
}

//18. Nodes at last level upto which tree is balanced
int maxWidth(Node *root)
{
    if(root==NULL){return 0;}
    queue<Node *> q;
    q.push(root);
    int res=0;
    while(q.empty()==false)
    {
        int count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++)
        {
            Node *current = q.front();
            q.pop();
            if(current->left!=NULL){q.push(current->left);}
            if(current->right!=NULL){q.push(current->right);}
        }
    }
    return res;
} 

//19. Convert Binary Tree into Doubly Linked List
//We use Inorder Traversal of Binary Tree
Node *prevs=NULL;
Node *BTtoDLL(Node *root)
{
    if(root==NULL){return root;}
    Node *head = BTtoDLL(root->left);
    if(prevs==NULL){head=root;}
    else
    {
        root->left=prevs;
        prevs->right=root;
    }
    prevs=root;
    BTtoDLL(root->right);
    return head;
}

//20. Construct A Binary Tree from Inorder and Preorder
int preIndex=0;
Node *cTree(int in[],int pre[],int is,int ie)
{
    if(is>ie){return NULL;}
    Node *root = new Node(pre[preIndex]++);

    int inIndex;
    for(int i=is;i<ie;i++)
    {
        if(in[i]==root->key)
        {
            inIndex=i;
            break;
        }
    }
    root->left=cTree(in,pre,is,inIndex-1);
    root->right=cTree(in,pre,inIndex+1,ie);
    return root;
}

//21. Print Binary Tree in Spiral Form
void printSpiral(Node *root)
{
    if(root==NULL){return;}
    queue <Node *> q;
    stack <int> s;
    bool reverse=false;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(reverse){s.push(curr->key);}
            else
            {
                cout<<curr->key<<" ";
            }
            if(curr->left!=NULL){q.push(curr->left);}
            if(curr->right!=NULL){q.push(curr->right);}
        }
        if(reverse)
        {
            while(s.empty()==false)
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<endl;
    }
    
}

//22. Diameter of A Binary Tree
int res=0;
int Diameter(Node *root)
{
    if(root==NULL) return 0;
    int lh=Diameter(root->left);
    int rh=Diameter(root->right);
    res=max(res,(1+rh+lh));
    return 1+max(lh,rh);
}

//23.24 Lowest Common Ancestor
Node *lca(Node *root,int n1,int n2)
{
    if(root==NULL){return root;}
    if(root->key==n1 || root->key==n2)
    {return root;}
    Node *lca1=lca(root->left,n1,n2);
    Node *lca2=lca(root->right,n1,n2);
    if(lca1!=NULL && lca2!=NULL)
    {
        return root;
    }
    if(lca1!=NULL)return lca1;
    else 
        return lca2;
}

//25. Burn Binary Tree from Leaf
int res1=0;
int burntime(Node *root,int leaf,int &dist)
{
    if(root==NULL)return 0;
    if(root->key==leaf){dist=0; return 1;}
    int ldist= -1;
    int rdist= -1;
    int lh=burntime(root->left,leaf,ldist);
    int rh=burntime(root->right,leaf,rdist);
    if(ldist!=-1)
    {
        dist=ldist+1;
        res1=max(res1,dist+rh);
    }
    else if(rdist!=-1)
    {
        dist=rdist+1;
        res1=max(res1,dist+lh);
    }
    return max(lh,rh)+1;
}
//26.Count Nodes in a Binary Tree
int countNodes(Node *root)
{
    int lh=0,rh=0;
    Node *curr = root;
    while(curr != NULL)
    {
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL)
    {
        rh++;
        curr=curr->right;
    }
    if(lh==rh)
    {
        return pow(2,lh)-1;
    }
    else
        return 1+countNodes(root->left)+countNodes(root->right);
}
//27. Serialize And Deserialize a Binary Tree
//Serialize
const int EMPTY=-1;
void Serialize(Node *root,vector<int>vect)
{
    if(root==NULL){vect.push_back(EMPTY); return;}
    vect.push_back(root->key);
    Serialize(root->left,vect);
    Serialize(root->right,vect);
}
//DeSerialize
const int EMPTY1=-1;
int index=0;
Node *Deserialize(vector<int>&vect)
{
    if(index==vect.size()) return NULL;
    int val = vect[index];
    index++;
    if(val==EMPTY) return NULL;
    Node *root = new Node(val);
    root->left=Deserialize(vect);
    root->right=Deserialize(vect);
    return root;
}
//28. Iterative Inorder Traversal
void iter_inorder(Node *root)
{
    stack<Node *>st;
    Node *curr=root;
    while(curr!=NULL || st.empty()==false)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}

//29. Iterative Preorder Traversal
void iter_preorder(Node *root)
{
    if(root==NULL) return;
    stack<Node *>st;
    st.push(root);
    while(st.empty()==false)
    {
        Node *curr = st.top();
        cout<<curr->key<<" ";
        st.pop();
        if(curr->right!=NULL) st.push(curr->right);
        if(curr->left!=NULL) st.push(curr->left);
    }

}

//30. Iterative Pre Order Traversal (Space Optimised)
void iterativePreorder(Node *root)
{
    if(root==NULL) return;
    stack<Node *> st;
    Node *curr=root;
    while(curr!=NULL && st.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            if(curr->right!=NULL) st.push(curr->right);
            curr=curr->left;
        }
        if(st.empty()==false){curr=st.top(); st.pop();}
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->right =new Node(5);
    root->left->left =new Node(4);
    root->right= new Node(30);
    root->right->right = new Node(50);
    root->right->left = new Node(40);
//          10
//      20         30
//   4      5    40      50
//
    //cout<<child_sum(root);
    //cout<<isBalanced(root);
    //cout<<maxWidth(root);
    //cout<<BTtoDLL(root);
    // int in[]={20,10,40,30,50};
    // int pre[]={10,20,30,40,50};
    // cout<<cTree(in,pre,0,4);
    //printSpiral(root);
    //cout<<Diameter(root);
    //cout<<lca(root,40,50);
    //cout<<countNodes(root);
    //vector<int> v1;
    //Serialize(root,v1);
    //vector<int>v2={10,20};
    //Deserialize(v2);

    return 0;
}
