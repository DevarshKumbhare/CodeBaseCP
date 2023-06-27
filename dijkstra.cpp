#include <bits/stdc++.h>//dijkstra simple implementation
using namespace std;//leetcode 743 based
const int N=1e5+10;
const int INF=1e9+10;

vector<pair<int,int>>g[N];
int dist[N];

int dijkstra(int source, int n, vector<pair<int,int>>g[N])
{
    vector<int>vis(N,0);
    vector<int>dist(N, INF);//initialising vis and dist arrays

    set<pair<int, int>>st;//weight, node sorted acc to first value aka weight
    st.insert({0,source});
    dist[source]=0;

    while(st.size()>0)// or just use (!st.empty()) same thing
    {
        auto node=*st.begin();
        int v=node.second;
        int v_dist=node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;

        for(auto child: g[v])
        {
            int child_v=child.first;
            int wt=child.second;//node and weight

            if(dist[v]+wt < dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(dist[i]==INF) return -1;
        ans=max(ans, dist[i]);
    }
    return ans;
}
//time complexity O(V+Elog(V)) E:edges, V:vertices

int main()
{
    int n,m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});//input directed and weighted
    }
    
}
