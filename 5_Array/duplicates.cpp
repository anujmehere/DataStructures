#include<iostream>
#include<vector>
using namespace std;
bool containsDuplicate(vector<int>& nums) 
{
	    bool val=false;
        int res=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums[res-1])
            {
            	cout<<"Not Equal"<<nums[i]<<" "<<nums[res-1]<<endl;
                nums[res]=nums[i];
                res++;
            }
            else if(nums[i]==nums[res-1])
            {
            	cout<<"Equal"<<nums[i]<<" "<<nums[res-1]<<endl;
            	val=true;
            	return val;
			}
            
        }
        return val;
        
}
int main()
{
    vector <int>n1={1,2,3,4};
    cout<<containsDuplicate(n1);
    return 0;

}