#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void k_closest(int arr[],int n,int k,int x)
{
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push({ abs(arr[i]-x),i});
    }
    for (int i = k; i < n; i++) 
    {
        int diff = abs(arr[i]-x);
        if (diff > pq.top().first)
            continue;
        pq.pop();
        pq.push({diff,i});
    }
    while (pq.empty() == false) {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}

int main()
{
    int arr[]={10,15,7,3,4};
    k_closest(arr,5,2,8);
    return 0;
}