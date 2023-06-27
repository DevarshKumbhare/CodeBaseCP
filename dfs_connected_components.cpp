#include <bits/stdc++.h>//basic dfs code
using namespace std;
const int N=1e5;

vector<int> g[N];
bool vis[N];//visited array

void dfs(int vertex)
{
    // take action on the vertex after entering the vertex
    vis[vertex]=true;
    for (int child: g[vertex])
    {
        if(vis[child]) continue;
        //take action on the child before entering the child
        dfs(child);
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
    int cnt=0;//count to store number of connected components
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}