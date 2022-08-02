#include<iostream>
#include<vector>
using namespace std;

//find max possible sum of a subarray of size k in an array of size n
int max_sumf(int arr[],int n,int k)
{
    //k is window size
    int curr_sum=0;
    for(int i=0;i<k;i++)
    {
        curr_sum+=arr[i];
    }
    int max_sum=curr_sum;
    for(int i=k;i<n;i++)
    {
        curr_sum+=(arr[i]-arr[i-k]);
        max_sum=max(curr_sum,max_sum);
    }
    return max_sum;
}

//find if given sum can be formed from a subarray in array of size n
vector<int> sub_sum(int arr[],int n,int sum)
{
    //s->start window  e->end window
    vector<int> v1;
    int curr_sum=arr[0];
    int s=0;
    int e;
    for(e=1;e<=n;e++)
    {
        while(curr_sum>sum && s<e-1)
        {
            curr_sum=curr_sum-arr[s];
            s++;
        }
        if(curr_sum==sum)
        {
            v1.push_back(s+1);
            v1.push_back(e);
            break;
        }
        if(e<n)
        {
            curr_sum=curr_sum+arr[e];
        }
    }
    return v1;
}
int main()
{
    int ar2[]={1,6,3,7,5};
    int n=5;int k=12;
    vector<int> v2=sub_sum(ar2,n,k);
    for(int x:v2) cout<<x<<" ";
}
