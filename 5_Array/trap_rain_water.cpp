#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) 
    {
    int n=height.size();
        if(n<3) return 0;
        int ans=0, left=0, right=n-1;
        int left_max=0, right_max=0;
        while(left<right) {
            left_max=max(height[left], left_max);
            right_max=max(height[right], right_max);
            if(height[left]>=height[right]) {
                ans+=min(left_max, right_max)-height[right];
                right--;
            }
            else {
                ans+=min(left_max, right_max)-height[left];
                left++;
            }
        }
     return ans;
    }

int main()
{
    vector<int> r1={1,8,6,2,5,4,8,3,7};
    cout<<trap(r1);
    return 0;
}