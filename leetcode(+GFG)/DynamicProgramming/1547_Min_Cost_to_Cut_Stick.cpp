#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][101];
    int f(int s, int e, int as, int ae, vector<int> &cuts)
    {
        // base case
        if (as > ae)
            return 0;

        if (dp[as][ae] != -1)
            return dp[as][ae];

        // recursive case
        int ans = INT_MAX;
        for (int i = as; i <= ae; i++)
        {
            ans = min(ans, (e - s) + f(s, cuts[i], as, i - 1, cuts) + f(cuts[i], e, i + 1, ae, cuts));
        }
        return dp[as][ae] = ans;
    }

    int minCost(int n, vector<int> &cuts)
    {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return f(0, n, 0, cuts.size() - 1, cuts);
    }
};

int main()
{
    return 0;
}

/**
 * @brief the array was sorted in order for the cuts to not be disorganized
 * sort the array allows to evaluate substate easily  
 * 
 */
