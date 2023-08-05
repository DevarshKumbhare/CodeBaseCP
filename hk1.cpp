#include <bits/stdc++.h>//Codeforces Round 877 (Div. 2)
#include<algorithm>
#include<array>
#include<set>
#include<bitset>
#include<list>
#include<iterator>
#include<regex>
#define ll long long
#define ld long double
#define endl '\n'
#define ull unsigned long long
#define ui unsigned int
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=10000;

ll t;

void solve()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>>g(m+1);
    vector<int> vis(m+1, 0);
    
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int start;
    cin>>start;
    
    deque<int>q;

    q.push_back(start);
    vis[start]=1;
    int max_dist=0;
    int last=0;
    
    cout<<q[0];
    
    while(!q.empty())
    {
        int l=q.size();
        last=q.front();
        
        for(int i=0; i<l; i++)
        {
            for(auto child: g[q[i]])
            {
                if(!vis[child])
                {
                    q.push_back(child);    
                    vis[child]=1;
                }
            }  
        }
        for(int i=0; i<l; i++)
        {
            q.pop_front();
        }
        max_dist++;
    }
    
    cout<<2*max_dist-1<<" "<<last<<endl;
    
}

int main()
{
cin>>t;
int t_=t;
while(t_!=0)
{
solve();
t_--;
}
}