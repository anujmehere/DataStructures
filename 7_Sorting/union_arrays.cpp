//union of two sorted arrays
//O(m+n) Time
//O(1) Aux Space
#include<iostream>
using namespace std;
void unionarr(int a[],int b[],int m,int n)
{
    int i=0,j=0;
    while(i<m && j<n )
    {
        if(a[i]==a[i-1]){i++; continue;}
        if(b[j]==b[j-1]){j++;continue;}
        if(a[i]<b[j])
        {
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]>b[j])
        {
            cout<<b[j]<<" ";
            j++;
        }
        else
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
    while(i<m && a[i-1]!=a[i])
    {
    	cout<<a[i]<<" ";
    	i++;
	}
	while(j<n && b[j-1]!=b[j])
	{
		cout<<b[j]<<" ";
		j++;
	}
}
int main()
{
    int ar1[]={10,20,20};
    int ar2[]={5,20,40,40};
    unionarr(ar1,ar2,3,4);

}