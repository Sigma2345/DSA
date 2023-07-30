// https: // leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, bool> vis;
    void dfs(int src, unordered_map<int, vector<int>> &h, int n)
    {
        vis[src] = true;
        for (int i = 0; i < h[src].size(); i++)
        {
            if (!vis[h[src][i]])
            {
                dfs(h[src][i], h, n);
            }
        }
        // return false ;
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        // dfs on edges
        unordered_map<int, vector<int>> h;
        for (int i = 0; i < roads.size(); i++)
        {
            h[roads[i][0]].push_back(roads[i][1]);
            h[roads[i][1]].push_back(roads[i][0]);
        }
        dfs(1, h, n);
        int ans = INT_MAX;
        for (int i = 0; i < roads.size(); i++)
        {
            if (vis[roads[i][0]] || vis[roads[i][1]])
            {
                ans = min(ans, roads[i][2]);
            }
        }
        return ans;
    }
};

// idea 
// -> dfs over the connected components of the graph connected with 1 and n 
// -> then check all roads where even one of the vertex is visited
// -> if it is visited then consider that weight 

