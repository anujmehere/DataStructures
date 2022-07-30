#include<iostream>
using namespace std;



int findTheWinner(int n, int k) {
    int ans=0;
    for(int i=1;i<=n;i++)
    {
       ans=(ans+k)%i; 
    }
    return ans+1;
        
    }

int main()
{
    cout<<findTheWinner(6,5);
    return 0;
}