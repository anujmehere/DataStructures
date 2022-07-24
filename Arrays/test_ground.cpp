#include<iostream>
#include<vector>
using namespace std;
//5,2,6,1
//traverse from back side

vector<int> countSmaller(vector<int>& nums) 
{
    vector<int> v1(nums.size(),0);
    int count=0;
    for(int i=nums.size();i>=1;i--)
    {
        if(nums[i-1]>nums[i])
        {
            count++;
        }
        else if(nums[i-1]>nums[i])
        {
            count--;
        }
        v1[i-1]=count;
    }
    return v1;
}

int main()
{
    vector<int> v2={8,9,7,4};
    vector<int> v3= countSmaller(v2);
    for(int x:v3)cout<<x<<endl;
}

// vector<int> v1;
//         for(int i=0;i<nums.size();i++)
//         {
//             int count=0;
//             for(int j=i;j<nums.size();j++)
//             {
//                 if(nums[j]<nums[i])
//                 { count++; }
//             }
//             v1.push_back(count);
//         }
//         return v1;