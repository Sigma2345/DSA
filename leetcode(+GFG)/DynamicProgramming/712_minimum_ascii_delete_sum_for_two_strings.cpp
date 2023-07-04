#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    int f(string &s1, string &s2, int i, int j)
    {
        // base case
        if (i == s1.length())
        {
            int ret = 0;
            for (int k = j; k < s2.length(); k++)
            {
                ret += s2[k];
            }
            return ret;
        }
        if (j == s2.length())
        {
            int ret = 0;
            for (int k = i; k < s1.length(); k++)
            {
                ret += s1[k];
            }
            return ret;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // rec
        if (s1[i] == s2[j])
        {
            return dp[i][j] = f(s1, s2, i + 1, j + 1);
        }
        return dp[i][j] = min(s1[i] + f(s1, s2, i + 1, j), s2[j] + f(s1, s2, i, j + 1));
    }

    int minimumDeleteSum(string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        return f(s1, s2, 0, 0);
    }
};

int main()
{
    return 0;
}
/**
 * @brief LCS + cost function attached 
 * memoize the solution
 */
