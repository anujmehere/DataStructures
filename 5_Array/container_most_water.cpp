#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) 
{
        int left=0, right=height.size()-1;
        int area=0;
        while(left<right) 
        {
            int temp=min(height[left],height[right])*(right-left);   
            area=max(area,temp);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }

        }
    return area;     
        
}











int main()
{
    vector<int> r1={1,8,6,2,5,12,8,3};
    cout<<maxArea(r1);
    return 0;
}