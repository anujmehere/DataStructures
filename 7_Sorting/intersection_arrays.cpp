//intersection of two sorted arrays
#include<iostream>
using namespace std;
void intersection(int a[],int b[],int m,int n)
{
    int i=0,j=0;
    while(i<m && j<n )
    {
    	if(i>0 && a[i-1]==a[i])
    	{
    		i++;
    		continue;
		}
        if(a[i]<b[j])
        {
            i++;
        }
        else if(a[i]>b[j])
        {
            j++;
        }
        else 
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
}
int main()
{
    int ar1[]={10,20,20,40,60};
    int ar2[]={2,20,50,60};
    intersection(ar1,ar2,5,4);

}