#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
       
        while(low<=high)
        {
        	int mid=(low+high)/2;
            if (nums[mid]==target)
            {
                return mid;
            }
            if(nums[low]<nums[mid])
            {
                if(target>=nums[low] && target<nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }    
            else
            {
                if(target>nums[mid] && target<=nums[high])
                {
                    low=mid+1;
                    cout<<"low"<<low;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }


int main()
{
    vector<int> a1={3,1};
    cout<<search(a1,1);
    //cout<<(5+4)/2;
    return 0;
}