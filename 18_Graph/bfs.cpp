#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Breadth First Traversal
//we first create a visited array of size = no of vertices and set value false
//then we set push(arr[s]) into queue and set visited[s]=true
//while
void bfs(vector<int> adj[],int v,int s)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u])
        {
            if(visited[x]==false)
            {
                visited[v]=true;
                q.push(x);
            }
        }
    }
}

void bfs_display(vector<int> adj[],int v)
{
    bool visited[v+1];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            bfs(adj,i,visited);
        }
    }

}