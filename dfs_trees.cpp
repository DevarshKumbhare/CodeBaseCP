#include <bits/stdc++.h>//dfs trees implementation for height and depth
using namespace std;
const int N=1e5;

vector<int> g[N];
int height[N], depth[N];

void dfs(int vertex, int par=0)
{
    // take action on the vertex after entering the vertex
    for (int child: g[vertex])
    {
        //take action on the child before entering the child
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child, vertex);
        height[vertex]=max(height[vertex], height[child]+1);
        //take action on child node after exiting the node
    }
    //take action on the vertex before exiting the vertex
}
//O(V+E) time complexity
int main()
{
    int n,m;//input as adjacency list
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}