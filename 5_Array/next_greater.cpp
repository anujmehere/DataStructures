#include<iostream>
#include<vector>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    //
    vector <int> res;
    for(int i=0;i<nums1.size();i++)
    {
        for(int j=0;j<nums2.size();j++)
        {
            if(nums1[i]==nums2[j])
            {
                for(int k=j;k<nums2.size();k++)
                {
                    if(nums2[k]>nums2[j])
                    {
                        res.push_back(nums2[k]);
                        break;
                    }
                    else if(k==(nums2.size()-1))
                    { res.push_back(-1);}
                }

            }
//          else{res.push_back(-1);}
        }
    }
    return res;
        
}

int main()
{
    vector <int> n1 = {4,1,2};
    vector <int> n2 = {1,3,4,2};
    vector <int> res= nextGreaterElement(n1,n2);
    for(int x:res){cout<<x<<" ";}
    return 0;
}