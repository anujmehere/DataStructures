#include<iostream>
#include<algorithm>
using namespace std;

int count_merge(int arr[], int low,int mid,int high)
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
    int res=0;
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
            res= res+(n1-k);
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
    return res;
    
}

int count_Inversion(int arr[],int l,int r)
{
    int res=0;
    if(r>l)
    {
        int mid=l+(r-l)/2;
        res+=count_Inversion(arr,l,mid);
        res+=count_Inversion(arr,mid+1,r);
        res+=count_merge(arr,l,mid,r);
    }
    return res;
}

int main()
{
    int arr[]={2,5,8,11,3,6,9,15};
    cout<<count_Inversion(arr,0,7)<<endl;
    for(int x:arr){cout<<x<<" ";}
    return 0;
}
