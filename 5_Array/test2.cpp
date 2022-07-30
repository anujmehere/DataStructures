#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>& height) 
{
	int n=height.size();
    int res=0;
	int lmax[n],rmax[n]; 
	lmax[0]=height[0];
	for(int i=1;i<n-1;i++)
	{
		lmax[i]=max(lmax[i-1],height[i]);
	}
	for(int j=n-1;j>=0;j--)
	{
		rmax[j]=max(rmax[j+1],height[j]);
	}
	for(int i=1;i<n-1;i++)
	{
		res = res+(min(lmax[i],rmax[i])-height[i]);
	}
	
	return res;
}

int main()
{
	vector<int> ar1 ={4,2,0,3,2,5};
	cout<<trap(ar1);
	return 0;
		
}