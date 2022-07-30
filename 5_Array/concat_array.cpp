#include<iostream>
using namespace std;
#include<vector>

vector<int> getConcatenation(vector<int>& nums) 
{
    
	vector<int> ans;
    for(int i=0;i<2*nums.size();i++)
            ans.push_back(nums[i%nums.size()]);
    
    
    return ans;  
        
}


int main()
{
    vector<int> num1 = {1,2,1};
    vector<int> res = getConcatenation(num1);
    for(int x:res)
    {
        cout<<x<<endl;
    }
    return 0;

}