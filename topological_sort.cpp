//topological sort
//Course Schedule II-leetcode-https://leetcode.com/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
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
 
class Solution {
public:
    vector<int>result;
    bool flag=true;

    void dfs(int curr, unordered_set<int>& para, vector<vector<int>>& g, vector<int>& vis)
    {
      if(para.find(curr) != para.end())
      {
        flag=false;
        return;
      }
      if(vis[curr]==1) return;

      vis[curr]=1;
      para.insert(curr);
      for(auto child: g[curr])
      {
        dfs(child, para, g, vis);
      }
      para.erase(curr);
      result.push_back(curr);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> de;
        
        for(int i=0; i<prerequisites.size(); i++)
        {
          g[prerequisites[i][0]].push_back(prerequisites[i][1]);//adj list
        }

        for(int i=0; i<numCourses; i++)
        {
          unordered_set<int>para;
          dfs(i, para, g, vis);//dfs on each node
        }

        if(flag==false) return de;
        return result;
    }
};