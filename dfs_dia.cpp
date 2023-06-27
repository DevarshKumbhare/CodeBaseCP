#include <bits/stdc++.h>//dfs trees calculating diameter
using namespace std;
const int N=1e5;

vector<int> g[N];
int depth[N];

void dfs(int v, int par=0)
{
    for(int child: g[v])
    {
        if(child==par) continue;
        depth[child]=depth[v]+1;
        dfs(child,v);
    }
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
    int max_depth=-1;
    int mx_d_node;
    for (int i = 1; i <= n; i++)
    {
        if(max_depth<depth[i])
        {
            max_depth=depth[i];
            mx_d_node=i;
        }
        depth[i]=0;
    }
    dfs(mx_d_node);
    for (int i = 1; i <= n; i++)
    {
        if(max_depth<depth[i])
        {
            max_depth=depth[i];
        }
    }
    cout<<max_depth<<endl;
}
