#include<iostream>
using namespace std;
#include<vector>

int maximumWealth(vector<vector<int>>& accounts) 
{
    int res;
    for (vector<int> ac : accounts)
    {
        int temp=0;
        for (int a : ac)
        {
            temp+=a;
        }   
        if(temp>res)
        {
            res=temp;
        } 
        
    }
    return res;
}

int main()
{ 
    vector<vector<int>> num1 = {{1,2,3},{3,2,1}};
    cout<< maximumWealth(num1);
    return 0;
}