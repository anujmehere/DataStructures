#include<iostream>
using namespace std;
#include<vector>
vector<int> runningSum(vector<int>& nums) 
{
    vector<int> ans;
    int sum=0;
    for(int i=0;i<nums.size();i++)
            ans.push_back(sum+=nums[i]);
    return ans;          
}

int main()
{
    vector<int> num1 = {-12356789,2,3,23456789};
    vector<int> res = runningSum(num1);
    for(int x:res)
    {
        cout<<x<<endl;
    }
    return 0;

}