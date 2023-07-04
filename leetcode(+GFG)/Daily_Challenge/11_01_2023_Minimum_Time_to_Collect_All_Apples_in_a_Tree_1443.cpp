// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lowestPath(int src, vector<vector<int>> &h, vector<bool> &hasApple, vector<int> &vis)
    {
        // recursive case
        vis[src] = true;
        int ans = 1;
        for (auto x : h[src])
        {
            if (!vis[x])
                ans += lowestPath(x, h, hasApple, vis);
        }
        vis[src] = false;

        if (!hasApple[src] && ans == 1)
            return 0;
        return ans + 1;
        // return edge needed if 
        // src has apple 
        // or children of src have apple
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> h(n);
        for (int i = 0; i < edges.size(); i++)
        {
            h[edges[i][0]].push_back(edges[i][1]);
            h[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, false);
        int x = lowestPath(0, h, hasApple, vis);
        return x == 0 ? 0 : x - 2;
        // if ans is positive then surely there is 2 counted extra for 0 node 
    }
};
