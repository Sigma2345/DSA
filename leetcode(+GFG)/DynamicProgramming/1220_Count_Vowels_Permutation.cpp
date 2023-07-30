// https://leetcode.com/problems/count-vowels-permutation/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<char, vector<char>> mp;
    map<char, int> mp1;
    int dp[30000][5];
    int MOD = 1e9 + 7;
    long long f(int n, char curr)
    {
        // base case
        if (n == 0)
            return 1;

        if (dp[n][mp1[curr]] != -1)
            return dp[n][mp1[curr]];

        // recursive case
        long long ans = 0;
        for (int i = 0; i < mp[curr].size(); i++)
        {
            ans += f(n - 1, mp[curr][i]);
            ans %= MOD;
        }
        return dp[n][mp1[curr]] = ans;
    }

    int countVowelPermutation(int n)
    {
        memset(dp, -1, sizeof(dp));
        mp['a'] = {'e', 'u', 'i'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'e', 'o'};
        mp['o'] = {'i'};
        mp['u'] = {'i', 'o'};

        mp1['a'] = 0, mp1['e'] = 1, mp1['i'] = 2, mp1['o'] = 3, mp1['u'] = 4;
        long long ans = 0;
        for (auto x : mp)
        {
            ans += f(n - 1, x.first);
            ans %= MOD;
        }
        return ans;
    }
};

// idea
// -> each char at mth position can be derived from certain number of characters at (m-1)th position
// -> so we iterate backwards and build the tree
