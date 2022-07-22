//Use of Recursion
//Many algorithm techniques are based on recursion Dynamic Programming,Backtrackng ,Divide and Conquer
//Many problems are inherently recursive ->tower of hanoi, traversal inorder,postorder,

#include<iostream>
using namespace std;


//print n->1 using recursion
void pr_n(int n)
{
    if(n==0)
        return;
    cout<<n<<" ";
    pr_n(n-1);
}

//print 1->n using recursion
void pr_1(int n)
{
    if(n==0)
        return ;
    pr_1(n-1);
    cout<<n<<" ";
}

//factorial of n
int factorial(int n)
{
    if(n==0 || n==1)
        return n;
    return n*factorial(n-1);
}

//nth fibonacci number
int fibo(int n)
{
    if(n==0 || n==1)
        return n;
    return fibo(n-1)+fibo(n-2);
}

//sum of natural nos using recusrion
int sumn(int n)
{
    if(n==0)
        return 0;
    return n+sumn(n-1);
}

//palindrome check using recursion
bool palind(string s1,int st,int end)
{
    if(st>=end)
        return true;
    return (s1[st]=s1[end] && palind(s1,st+1,end-1));
}

//sum of digits using recursion
int sumd(int n)
{
    if(n==0)
        return 0;
    return (n%10)+sumd(n/10);
}

//rope cutting problems
//find max num of ways in which a rope of length l can be cut into parts a,b,c
int ropecut(int l,int a,int b, int c)
{
    if(l==0) return 0;
    if(l<0) return -1;
    int res = max(ropecut(l-a,a,b,c),max(ropecut(l-b,a,b,c),ropecut(l-c,a,b,c)));
    if(res==-1) return res;
    else return res+1;
}

//Subsets of a string
//same as powerset of a string in bit manipulation
//abc ={"","a","b","c","ab","ac","bc","abc"}
//Check code again///////////////////////////////////////////////////////////////////////////////////////////
void subset(string s,string curr="",int i=0)
{
    if(i==s.length())
    {
        cout<<curr<<endl;
        return;
    }
    subset(s,curr,i+1);
    subset(s,curr+s[i],i+1);
}

//Tower of Hanoi problem
//there are a,b,c number of disks in 3 towers with numbering. you need to arrange this disks in last tower
// we take help of recursion
void toh(int n,int a,int b,int c)
{
    if(n==1)
    {
        cout<<"move 1 from"<<a<<"to"<<c<<endl;
        return;
    }
    toh(n-1,a,c,b);
    cout<<"move "<<n<<" from "<<a<<"to"<<c<<endl;
    toh(n-1,b,a,c);
}

//josephus problem
//n people in a circle -> every kth person is killed. find the survivor
int jos(int n,int k)
{
    if(n==1)
        return 0;
    else
        return (jos(n-1,k)+k)%n;
}

//count number of subsets possible in a set for a given sum
int cntsubset(int arr[], int n,int sum)
{
    if(n==0)
    { return (sum==0)? 1:0;}
    return cntsubset(arr,n-1,sum)+cntsubset(arr,n-1,sum-arr[n-1]);
}

//find all permutations of a string
void permute(string s,int i=0)
{
    if(i==s.length()-1)
    {
        cout<<s<<" ";return;
    }
    for(int j=1;j<s.length();j++)
    {
        swap(s[i],s[j]);
        permute(s,i+1);
        swap(s[i],s[j]);
    }
}
int main()
{
    cout<<jos(5,3);
}