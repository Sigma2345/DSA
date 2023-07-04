#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> h(n);
        for (int i = 0; i < edges.size(); i++)
        {
            h[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (h[i].size() == 0)
                ans.push_back(i);
        }
        return ans;
    }
};

// reverse the edges and count nodes with 0 outgoing edges
// those are the edges that have 0 incoming edges in original graph
// they are the vertices
