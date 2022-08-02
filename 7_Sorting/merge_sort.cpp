#include<iostream>
#include<vector>
using namespace std;

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

int main()
{
    int a1[] = {10,5,30,15,7};
    for(int x:a1){cout<<x<<" ";}
    cout<<endl;
    mergeSort(a1,0,4);
    for(int x:a1){cout<<x<<" ";}
    return 0;
}

