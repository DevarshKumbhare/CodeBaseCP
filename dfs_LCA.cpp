#include <bits/stdc++.h>//dfs trees Lower common Ancestor
using namespace std;
const int N=1e5;

vector<int> g[N];
int parent[N];

void dfs(int v, int par=-1)
{
    parent[v]=par;
    for(int child: g[v])
    {
        if(child==par) continue;
        dfs(child, v);
    }
}

vector<int> path(int v)
{
    vector<int>ans;
    while(v!=-1)
    {
        ans.push_back(v);
        v=parent[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

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
    dfs(1);
    int x, y;
    cin>>x>>y;
    vector<int>path_x=path(x);
    vector<int>path_y=path(y);
    int l=min(path_x.size(), path_y.size());
    int lca=-1;
    for (int i = 0; i < l; i++)
    {
        if(path_x[i]==path_y[i]) lca=path_x[i];
        else break;
    }
    cout<<lca<<endl;
}