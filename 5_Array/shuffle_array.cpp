#include<iostream>
using namespace std;
#include<vector>
vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans;
        for(int i=0;i<n;i=i+1)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[n+i]);
        }
        return ans;
    
}


int main()
{ 
    vector<int> num1 = {2,5,1,3,4,7};
    int n1 =3;
    vector<int> res = shuffle(num1,n1);
    for(int x:res)
    {
    	cout<<x<<" ";
	}
    return 0;
}