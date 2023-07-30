// https://leetcode.com/problems/stone-game-ii/description/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][101];
    int f(vector<int> &piles, int i, int maxAllowed, vector<int> &sufsum)
    {
        // base case
        if (i == piles.size())
            return 0;
        // recursive case

        if (dp[i][maxAllowed] != -1)
            return dp[i][maxAllowed];

        int ans = 0, sum = 0;
        for (int j = i; j < piles.size() && j < i + 2 * maxAllowed; j++)
        {
            ans = max(ans, sum + sufsum[j] - f(piles, j + 1, max(j - i + 1, maxAllowed), sufsum));
            sum += piles[j];
        }
        return dp[i][maxAllowed] = ans;
    }
    int stoneGameII(vector<int> &piles)
    {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        vector<int> sufsum(n);
        sufsum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            sufsum[i] = sufsum[i + 1] + piles[i];
        }

        return f(piles, 0, 1, sufsum);
    }
};

// sufsum[j] - f(piles, j + 1, max(j - i + 1, maxAllowed), sufsum)
// ABOVE EXPRESSION IS 
// TOTAL STONES COLLECTED AFTER OTHER PLAYER HAS COLLECTED TILES
