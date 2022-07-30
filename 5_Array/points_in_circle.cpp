#include<iostream>
using namespace std;
#include<vector>

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
{
    vector<int> result;
    for(int i=0;i<queries.size();i++)
    {
        int temp=0;
        for(int k=0;k<points.size();k++)
        {
           //cout<<(queries[i][0]+queries[i][2])<<">"<<points[k][0]<<">"<<(queries[i][0]-queries[i][2])<<" &&"<< (queries[i][1]+queries[i][2])<<">"<<points[k][1]<<">"<<(queries[i][1]-queries[i][2]) <<endl;
           if((queries[i][0]+queries[i][2])>=points[k][0] && points[k][0]>=(queries[i][0]-queries[i][2])   )
           {
               if((queries[i][1]+queries[i][2])>=points[k][1] && points[k][1]>=(queries[i][1]-queries[i][2]))
               {
               temp++;
               }
           }
        }
        result.push_back(temp);
    }
    return result;

}

int main()
{
    vector<vector<int>>p1= {{1,3},{3,3},{5,3},{2,2}};
    vector<vector<int>>q1= {{2,3,1},{4,3,1},{1,1,2}};
    vector <int> res = countPoints(p1,q1);
    for(int x:res)
	{
		cout<<x<<" ";
	}

    return 0;
}