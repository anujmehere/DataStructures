#include<iostream>
#include<algorithm>
using namespace std;

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

int main()
{
    int arr[]={4,1,3,2,5};
    insertionsort(arr,5);
    for(int x:arr){cout<<x<<" ";}
    return 0;
}
