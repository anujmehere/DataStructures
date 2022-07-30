#include<iostream>
using namespace std;
//iterative
int bsearch(int arr[],int n,int x)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            h=mid-1;
        else if(arr[mid]<x)
            l=mid+1;
    }
    return -1;
}

//recursive binary search
int recbsearch(int arr[],int n,int x,int low,int high)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x) return mid;
    if(arr[mid]>x)
        recbsearch(arr,n,x,mid+1,high);
    else
        recbsearch(arr,n,x,low,mid-1);
}

int main()
{
    int ar2[]={1,2,3,4,5};
    cout<<recbsearch(ar2,5,4,0,4);
    return 0;
}