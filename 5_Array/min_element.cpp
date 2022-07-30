#include<iostream>
#include<vector>
using namespace std;
int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high)
        {
        if(nums[low]<nums[high])
            return nums[low];
        int mid=(low+high)/2;
        if(nums[low]==nums[mid])
            low++;
        else if(nums[mid]>nums[low])
            low=mid+1;
        else
            high=mid;
        }
        return nums[low]; 
    }

int main()
{
    vector<int> a1={1,3,5};
    cout<<findMin(a1);
    return 0;
}