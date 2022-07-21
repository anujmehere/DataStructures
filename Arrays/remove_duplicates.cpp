#include<iostream>
#include<vector>
using namespace std;

vector<int> removeDuplicates(vector<int>& nums) 
{
    vector<int> nums2;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=nums[i+1])
        {
            nums2.push_back(nums[i]);
        }
    }
    return nums2;    
}

int main()
{
    vector<int> v2 = {0,0,1,1,1,2,2,3,3,4};
    vector<int> v3;
    v3 = removeDuplicates(v2);
    for(int x:v3)cout<<x<<" ";
}