#include<iostream>
#include<vector>
using namespace std;
vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size() , lo = 0 , hi = n-1;
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++)
            if(nums[i] < pivot){ans[lo]=nums[i];lo++;}
        for(int i = n-1 ; i >= 0 ; i--)
            if(nums[i] > pivot){ans[hi]=nums[i];hi--;}
        while(lo<=hi)
        {
            ans[lo]=pivot;lo++;
        }
        return ans;
        
        
    }

int main()
{
    vector<int> v1={-3,4,3,2};
    int pivot=2;
    v1=pivotArray(v1,pivot);
    for(int x:v1){cout<<x<<" ";}
}