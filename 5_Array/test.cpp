#include<iostream>
using namespace std;
//greatest element reachest last pos first
void bbsort(int arr[],int n)
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
int main()
{
    int a2[]={1,5,2,4,3};
    bbsort(a2,5);
    for(int x:a2)cout<<x<<" ";
}