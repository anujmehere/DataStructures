#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n=5;
    vector<vector<int>> v1(n);
    for(int i=0;i<n;i++)
    {
        v1[i].resize(i+1);
        v1[i][0]=v1[i][i]=1;
        for(int j=1;j<i;j++)
        {
            v1[i][j]=v1[i-1][j-1]+v1[i-1][j];
        }
    }
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cout<<v1[i][j];
        }
        cout<<endl;
    }
}