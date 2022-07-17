#include<iostream>
using namespace std;
//Pivot --> point around which we want to partition the array
//Lomuto Partition
//we treat pivot always as last element
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