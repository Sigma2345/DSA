#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[51][51][11];
    int pizzaCnt[51][51];
    int MOD = 1e9 + 7;
    int cntPizza(vector<string> &pizza, int st_row, int st_col, int en_row, int en_col)
    {
        int ans = pizzaCnt[en_row][en_col] + pizzaCnt[st_row][st_col] - pizzaCnt[en_row][st_col] - pizzaCnt[st_row][en_col];
        // cout<<ans<<endl ;
        return ans;
    }
    int f(vector<string> &pizza, int row, int col, int k)
    {
        // base case
        if (k == 0 && cntPizza(pizza, row, col, pizza.size(), pizza[0].length()))
            return 1;
        if (row >= pizza.size() || col >= pizza[0].length())
            return 0;
        // vertical cuts + horizontal cuts

        if (dp[row][col][k] != -1)
            return dp[row][col][k];

        int ans = 0;
        // vertical cuts
        for (int i = row + 1; i < pizza.size(); i++)
        {
            if (cntPizza(pizza, row, col, i, pizza[0].length()) >= 1)
                ans += f(pizza, i, col, k - 1);
            ans %= MOD;
        }
        // horizontal cuts
        for (int i = col + 1; i < pizza[0].length(); i++)
        {
            if (cntPizza(pizza, row, col, pizza.size(), i) >= 1)
                ans += f(pizza, row, i, k - 1);
            ans %= MOD;
        }
        return dp[row][col][k] = ans;
    }
    int ways(vector<string> &pizza, int k)
    {
        memset(dp, -1, sizeof(dp));
        memset(pizzaCnt, -1, sizeof(pizzaCnt));
        for (int i = 1; i <= pizza.size(); i++)
        {
            for (int j = 1; j <= pizza[0].length(); j++)
            {
                int x = pizzaCnt[i - 1][j];
                int y = pizzaCnt[i][j - 1];
                int z = -pizzaCnt[i - 1][j - 1];
                pizzaCnt[i][j] = x + y + z;
                if (pizza[i - 1][j - 1] == 'A')
                {
                    pizzaCnt[i][j]++;
                }
            }
        }

        return f(pizza, 0, 0, k - 1);
    }
};
