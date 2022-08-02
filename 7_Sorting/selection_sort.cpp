#include<iostream>
#include<algorithm>
using namespace std;

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

int main()
{
    int arr[]={4,1,3,2,5};
    selectionsort(arr,5);
    for(int x:arr){cout<<x<<" ";}
    return 0;
}
