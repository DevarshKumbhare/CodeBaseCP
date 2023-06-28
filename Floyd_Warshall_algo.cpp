#include <bits/stdc++.h>//Floyd Warshall Algorithm
using namespace std;//every node to every other node shortest dist
const int N=510;//Dijsktra was one start node to every other node
const int INF=1e9+10;

int dist[N][N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    int n,m;
    cin>>n>>m;//input vertex and edges
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin>>x>>y>>wt;
        dist[x][y]=wt;
    }

    for (int k = 1; k < n; k++)//levels or number of nodes allowed to traverse through
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF)//specifically put for the neagtive cases given below
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
            
        }
        
    }
    //(k-1)th level calculated min dist, so either adding kth level will cause same min value of it will change to dist of i-->k and k-->j

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dist[i][j]==INF) cout<<"I"<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
//points to remember:
//->can handle negative weights
//->cant handle negative weighted cycle-coz it goes in an infinite loop and the value of min keeps on decreasing as a loop completes
//dist[i][k]+dist[k][j] where (-ve value)+(INF) will reduce the INF which we dont want as edge doesnt exist in that case
