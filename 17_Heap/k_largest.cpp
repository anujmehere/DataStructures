#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//here max heap approach provides a solution in O(n)+O(k*logn)
//better min heap approach provides a solution in O(k)+O((n-k)*logK)
void klargest(int v[],int n,int k)
{
    priority_queue<int ,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(v[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(pq.top()<v[i])
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    while(pq.empty()==false)
    {
        cout<<pq.top();
        pq.pop();
    }
}

int main()
{
    int v[]= {5,15,10,20,8,25,18};
    klargest(v,7,3);
}