#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestWeight;
    vector<vector<int>> s; 

    int find(int x, vector<int> &p)
    {
        return p[x] == -1 ? x : p[x] = find(p[x], p);
    }

    void merge(int x, int y, vector<int> &p)
    {
        x = find(x, p), y = find(y, p);
        if (x > y)
            swap(x, y);
        p[y] = x;
    }

    void bestMST(vector<vector<int>> &v, int n)
    {
        bestWeight = 0;
        vector<int> p(n, -1);
        for (int i = 0; i < v.size(); i++)
        {
            if (find(v[i][0], p) != find(v[i][1], p))
            {
                bestWeight += v[i][2];
                merge(v[i][0], v[i][1], p);
                s.push_back(v[i]); 
            }
        }
    }

    bool isMSTPossible(vector<vector<int>> &v, int x, int n)
    {
        vector<int> p(n, -1);
        int wt = 0;
        for (int i = 0; i < v.size() && wt <= bestWeight; i++)
        {
            if (i == x)
                continue;
            if (find(v[i][0], p) != find(v[i][1], p))
            {
                wt += v[i][2];
                merge(v[i][0], v[i][1], p);
            }
        }

        if (wt > bestWeight)
            return false;
        for (int j = 0; j < n; j++)
        {
            if (find(j, p) != 0)
                return false;
        }

        return true;
    }

    int getMSTWeight(vector<int> &s, int n){
        
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &v)
    {
        vector<vector<int>> ans(2);
        // finding critical
        for (int i = 0; i < v.size(); i++)
        {
            v[i].push_back(i);
        }
        sort(begin(v), end(v), [](const auto &a, const auto &b)
             { return a[2] <= b[2]; });
        bestMST(v, n);
        for (int i = 0; i < v.size(); i++)
        {
            bool check = isMSTPossible(v, i, n);
            if (!check)
            {
                ans[0].push_back(v[i][3]);
            }
        }
        // finding non critical
        for (int i = 0; i < n; i++){
            s.push_back(v[i]);
            int wt = getMSTWeight(s, n); 
            s.pop_back();
        }
    }
};
