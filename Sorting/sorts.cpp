#include<iostream>
using namespace std;
//Bubble Sort 
//The array is sorted by first fixing the largest element at the end position
//We optimize the code using swapped variable i.e. if no single swap occurs in an iteration implies that 
//array is already sorted.
void bubblesort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
                swapped=true;
        }
        if(swapped==false)
        {
            break;
        }
    }
}

//Selection Sort
//1.Reduces memory rides 2.Basis for Heapsort  3.Not stable 4. In place
//Find min element and fix it at first pos
//theta(n^2) time

void selectionsort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int min_ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_ind])
            {
                min_ind=j;
            }
        }
        swap(arr[min_ind],arr[i]);
    }
}


//Insertion Sort 
//1.Inplace 2.Stable 3.Used for small arr (timsort/introsort) 4. O(n)best O(n^2)worst case time
//1.timsort->merge+insertion  2.introsort->heap+quick+insertion
//keep one part sorted and other unsorted -> insert element at apprp. pos to get sorted arr
void insertionsort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

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
//nlogn merge sort quick sort

int main()
{
    int ar2[]={12,1,48,32,24};
    bubblesort(ar2,5);
    for(int x:ar2)cout<<x<<" ";
}