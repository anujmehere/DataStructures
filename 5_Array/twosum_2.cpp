#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) 
{
    vector <int> res;
    int low=0,high=numbers.size()-1;
    while(low<=high)
    {
        int temp=numbers[low]+numbers[high];
        if(temp>target)
        {
            high--;
        }
        else if(temp<target)
        {
            low++;
        }
        else if(temp==target)
        {
            res.push_back(low+1);
            res.push_back(high+1);
        }
    }
    for(int x:res){cout<<x;}

}
int main()
{
    vector<int> num1 ={2,7,11,15};
    int t1=9;
    twoSum(num1,t1);
    return 0;
}