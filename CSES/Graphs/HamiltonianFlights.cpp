#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int check;
long long f(int pos, vector<vector<int>> &h, int mask, int n, vector<vector<int>> &dp)
{
    // base case
    if (pos == n)
        return mask == check ? 1 : 0;

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    // rec
    long long ans = 0;
    for (int i = 0; i < h[pos].size(); i++)
    {
        if(!(mask&(1<<h[pos][i])))
            ans += f(h[pos][i], h, mask ^ (1 << pos), n, dp) % MOD;
        ans %= MOD;
    }
    return dp[pos][mask] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, m;
    cin >> n >> m;
    check = pow(2, n) - 2;
    vector<vector<int>> h(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        h[a].push_back(b);
    }
    vector<vector<int>> dp(n, vector<int>(pow(2, n), -1));
    cout << f(1, h, 0, n, dp) << endl;

    return 0;
}
