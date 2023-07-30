// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
#include<bits/stdc++.h>
using namespace std; 
class Solution
{
public:
    int ans = 0;
    int f(vector<vector<int>> &h, vector<int> &vis, int src, string &s)
    {

        vis[src] = true;
        priority_queue<int, vector<int>, greater<int>> pq;
        int maxLength = 0;

        for (auto child : h[src])
        {
            if (!vis[child] && s[child] != s[src])
            {
                int x = f(h, vis, child, s);
                maxLength = max(maxLength, x);
                pq.push(x);
                if (pq.size() > 2) // to find largest 2 branches from root 
                {
                    pq.pop();
                }
            }
        }

        int sum = 0;
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        ans = max(ans, sum + 1);
        return maxLength + 1; // only one branch can be sent if path goes to above node 
    }

    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        if (n == 1)
            return 1;
        vector<vector<int>> h(n);
        for (int i = 1; i < n; i++)
        {
            h[parent[i]].push_back(i);
            h[i].push_back(parent[i]);
        }
        vector<int> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i]) // some nodes not visited since their parent has same character
            {
                f(h, vis, i, s);
            }
        }
        return ans;
    }
};
