#include<iostream>
using namespace std;
//Pivot --> point around which we want to partition the array
//Lomuto Partition
//we treat pivot always as last element
//if pivot is input swap it with last element
//Time O(n)
int lPartition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}



//Hoare's Partition
//first element as pivot
int hpartition( int arr[], int l,int h)
{
    int pivot=arr[l];
    int i=l-1;int j=h+1;

}

int main()
{
    int ar2[]={5,3,8,4,2,7,1,10};
    hpartition(ar2,0,7);
    for(int x:ar2)cout<<ar2<<" ";
}