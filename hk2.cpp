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
 
int dfs(int curr, vector<int>& vis, vector<vector<int>>& g)
{
    vis[curr]=1;
    int min_ele=curr;
    for(auto child: g[curr])
    {
        if(!vis[child]) min_ele=min(min_ele, dfs(child, vis, g));
    }
    return min_ele;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<int> vis(n+1,0);

    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int>v;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]) v.push_back(dfs(i, vis, g));
    }
    int number=v.size()-1;
    sort(v.begin(), v.end(), greater<int>());
    long long cost=0;

    for (int i = 0; i < v.size()-1; i++)
    {
        cost+=v[i]+v[i+1];
    }

    cout<<number<<" "<<cost;

    for (int i = 0; i < v.size()-1; i++)
    {
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
    
      
}

int main()
{
solve();
}