#include<iostream>
using namespace std;
#include<vector>
vector<int> sumZero(int n) 
{
    vector<int> ans;
    if (n==1)
    {
        ans.push_back(0);
        return ans;
    }
    
    if (n%2==0)
    {
        for (int i=-n/2; i<0; i++)
        {
            ans.push_back(i);
        }
        for (int i=1; i<=n/2; i++)
        {
            ans.push_back(i);
        }
    }
    else
    {
        int temp= (-n/2);
    for(int i=0;i<n;i++)
    {
        ans.push_back(temp);
        temp++;
    }
    }
    return ans;
}
int main()
{
    int n=4;
    vector<int> res = sumZero(n);
    for(int x:res)
    {
        cout<<x<<endl;
    }
    return 0;
}