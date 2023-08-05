//https://www.youtube.com/watch?v=wjYnzkAhcNk
//https://leetcode.com/problems/find-the-duplicate-number/
//Floyd's algorithm to find start of the cycle in a linked list
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
/*
    Given int array, return the one repeated number
    Ex. nums = [1,3,4,2,2] -> 2, nums = [3,1,3,4,2] -> 3

    If there's duplicate, must be a cycle, find meeting point
    Take 1 back to start, they'll intersect at the duplicate

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int quick = nums[nums[0]];
        
        while (slow != quick) {//part1: find intersection of slow and fast pointer in cycle
            slow = nums[slow];
            quick = nums[nums[quick]];
        }
        
        slow = 0;
        while (slow != quick) {//from there and start of linked list, both are equidistant to the start of the cycle
            slow = nums[slow];
            quick = nums[quick];
        }
        return slow;
    }
};