#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b)
{
if(a.first==b.first)
    return a.second>b.second ;
else 
    return a.first<b.first;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long  tar,n;
    cin>>tar>>n;
    vector<long>supply(n,0);
    vector<long >cost(n,0);
    int ven=0;
    
    for(int i=0;i<n;i++)
        cin>>supply[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    vector<pair<long long,long long >>v;
    for(int i=0;i<n;i++)
        v.push_back({cost[i],supply[i]});//
    sort(v.begin(),v.end(),comp);
    int res=0;
    int i=0;
    while(i<n&&tar>0)
    {
    int c=v[i].first;
    int s=v[i].second;
        i++;
    if(tar>=s)//buy full 
    {
    res+=s*c;
    tar-=s;
        ven++;
    }
    else //tar<s
    {
        res+=tar*c;
        ven++;
        tar=0;
    }
        
    if(tar==0)
    cout<<res<<" "<<ven;
    else 
    cout<<res;
}