#include<iostream>
#include<algorithm>
using namespace std;

void bubblesort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapped=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(swapped==false)
        {
            break;
        }
    }
}

int main()
{
    int arr[]={4,1,3,2,5};
    bubblesort(arr,5);
    for(int x:arr){cout<<x<<" ";}
    return 0;
}
