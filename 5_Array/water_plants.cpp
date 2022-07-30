#include<iostream>
#include<vector>
using namespace std;

int wateringPlants(vector<int>& plants, int capacity) 
    {
        int steps=0;
        int cap1=capacity;
        for(int i=0;i<plants.size();i++)
        {
            if(cap1>=plants[i])
            {
                steps++;
                cap1=cap1-plants[i];   
            }
            else if(cap1<plants[i])
            {
                steps=steps+((2*i)+1);
                cap1=capacity - plants[i];
                
            }
        }
        return steps;
    }
int main()
{
	vector<int> n1 ={3,2,4,2,1};
    cout<<wateringPlants(n1,6);
    return 0;
}