#include<iostream>
using namespace std;
//Merge Sort
//1. Divide Conquer And Merge 2.Stable 3.Time theta(nlogn) 4.Space O(n) 5.Best for Link List as space O(1)
//6. USed in external sorting  7.For arrays,Quicksort outperforms it.
void merge(int arr[],int low,int mid, int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){left[i]=arr[low+i];}
    for(int j=0;j<n2;j++){right[j]=arr[mid+1+j];}
    int k=0;
	int l=0;
	int m=low;
    while(k<n1 && l<n2)
    {
        if(left[k]<=right[l])
        {
            arr[m]=left[k];
            m++;
            k++;
        }
        else
        {
            arr[m]=right[l];
            l++;
            m++;
        }
    }
    while (k<n1)
    {
        arr[m]=left[k];
        m++;
        k++;
    }
    while (l<n2)
    {
        arr[m]=right[l];
        m++;
        l++;
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(r>l)
    {
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}