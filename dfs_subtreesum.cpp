#include <bits/stdc++.h>//dfs trees subtree sum or number of even numbers in subtree of v
using namespace std;
const int N=1e5;

int subtree_sum[N];
int val[N];
int even_count[N];

vector<int> g[N];


void dfs(int vertex, int par=0)
{
    // take action on the vertex after entering the vertex
    if(vertex%2==0) even_count[vertex]++;
    subtree_sum[vertex]+=val[vertex];
    for (int child: g[vertex])
    {
        //take action on the child before entering the child
        if(child==par) continue;
        dfs(child, vertex);
        //take action on child node after exiting the node
        subtree_sum[vertex]+=subtree_sum[child];
        even_count[vertex]+=even_count[child];
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
    int q;
    cin>>q;
    dfs(1);
    while (q--)
    {
        int v;
        cin>>v;
        cout<<subtree_sum[v]<<" "<<even_count[v]<<endl;
    }

}