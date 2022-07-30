#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<vector<int>> v2;
    for(int arr=0;arr<intervals.size()-1;arr++)
    {
        if(intervals[arr+1][0]<intervals[arr][1])
        {
            v2.push_back(intervals[arr][0],intervals[arr+1][1])
        }
    }
}

int main()
{
    vector<vector<int>>v1 ={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>v2=merge(v1);
    for(auto x:v2)
    {cout<<x[0]<<x[1]<<""<<endl;}
}