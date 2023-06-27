#include <bits/stdc++.h>//bfs basic implementation
using namespace std;
const int N=1e5;

vector<int> g[N];

int vis[N];//previously visited array
int level[N];// stores level or the shortest path between the source vertex and the given node

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;

    while(!q.empty())
    {
        int curr_v=q.front();
        q.pop();
        for(int child: g[curr_v])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[curr_v]+1;
            }
        }
    }
}//O(V+E) time complexity of BFS

//shortest path qns provided edges have equal weights

int main()
{
    int n;//input as adjacency list
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bfs(1);
}