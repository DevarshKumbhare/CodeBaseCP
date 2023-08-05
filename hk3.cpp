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
 
void solve()
{
    int l,r,c,k;
    cin>>l>>r>>c>>k;
    
    vector<vector<vector<int>>>matrix;

    for (int i = 0; i < 50; i++)
    {
        vector<vector<int>>r;
        for (int j = 0; j < 50; i++)
        {
            vector<int>temp(50,0);
            r.push_back(temp);
        }
        matrix.push_back(r);
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int p = 0; p < c; p++)
            {
                cin>>matrix[j][p][i];
            }
            
        }
        
    }

    int start_i, start_j, start_k;
    cin>>start_i>>start_j>>start_k;
    
    int end_i, end_j, end_k;
    cin>>end_i>>end_j>>end_k;

    deque<vector<int>>q;




}

int main()
{
solve();
}