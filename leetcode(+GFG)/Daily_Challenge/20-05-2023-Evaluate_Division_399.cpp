#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        int i = 0;
        unordered_map<string, int> map;
        for (auto e : equations)
        {
            if (map.find(e[0]) == map.end())
                map[e[0]] = i++;
            if (map.find(e[1]) == map.end())
                map[e[1]] = i++;
        }
        vector<double> ans;
        vector<vector<double>> dp(map.size(), vector<double>(map.size(), -1));
        for (int i = 0; i < equations.size(); i++)
        {
            int u = map[equations[i][0]];
            int v = map[equations[i][1]];
            dp[u][v] = values[i];
            dp[v][u] = 1 / values[i];
        }
        int o = 0;
        while (o < dp.size())
            dp[o][o++] = 1;

        for (int k = 0; k < dp.size(); k++)
            for (int i = 0; i < dp.size(); i++)
            {
                for (int j = 0; j < dp.size(); j++)
                {
                    if (dp[i][k] == -1 || dp[k][j] == -1)
                        continue;
                    if (dp[i][j] == -1)
                        dp[i][j] = dp[i][k] * dp[k][j];
                    else
                        dp[i][j] = min(dp[i][j], dp[i][k] * dp[k][j]);
                }
            }

        for (auto i : queries)
        {
            if (map.find(i[0]) == map.end() || map.find(i[1]) == map.end())
            {
                ans.push_back(-1);
                continue;
            }

            int u = map[i[0]];
            int v = map[i[1]];
            if (u == v)
                ans.push_back(1);
            else if (dp[u][v] != -1)
            {
                ans.push_back(dp[u][v]);
            }
            else if (dp[u][v] == -1)
            {
                if (dp[v][u] != -1)
                    ans.push_back(1 / dp[v][u]);
                else
                    ans.push_back(-1);
        }
            }
        return ans;
    }
};

int main()
{
    return 0;
}

/**
 * @brief the main idea is that a/b , b/c, bc/cd is given we dont need to reduce  
 * bc/cd to b/d 
 * so floyd warshall can be used 
 */
