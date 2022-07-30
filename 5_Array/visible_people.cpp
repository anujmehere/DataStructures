#include<iostream>
#include<vector>
using namespace std;
vector<int> canSeePersonsCount(vector<int>& heights) 
{
    vector <int> res;
    for(int i=0;i<heights.size();i++)
    {
        int temp=0;
        bool view=true;
        for(int j=i+1;j<heights.size();j++)
        {
            if(heights[j]<heights[i] && view==true)
            {
                cout<<heights[i]<<">"<<heights[j]<<endl;
                temp++;
            }
            else if(heights[j]>heights[i] && view==true)
            {
                cout<<heights[i]<<">"<<heights[j]<<endl;
                temp++;
                view=false;
            }
            continue;
        }
        res.push_back(temp);
    }
    return res;
        
}



int main()
{
    vector <int>h1 = {10,6,8,5,11,9};
    vector <int>h2;
    h2=canSeePersonsCount(h1);
    for(int x:h2){cout<<x<<" ";}
    return 0;
}