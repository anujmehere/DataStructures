#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int max_items(int arr[],int sum,int n)
{
    priority_queue<int, vector<int>, greater<int>>pq(arr,arr+n);
    int res=0;
    while(sum>pq.top())
    {
        sum=sum-pq.top();
        res++;
        pq.pop();
    }
    return res;
}

int main()
{
    int ar2[]={1,12,5,111,200};
    cout<<max_items(ar2,10,5);
}