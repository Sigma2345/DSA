#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<p64> vp64;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define int long long

int f(vp64 &h, vp64 &g, int i, int j, bool onh, vector<vector<vector<int>>> &dp)
{
    if (i == h.size())
    {
        int sum = 0;
        int diff = abs(g[j].first - h[i - 1].first) + abs(g[j].second - h[i - 1].second);
        sum += diff * diff;
        for (int k = j + 1; k < g.size(); k++)
        {
            diff = abs(g[k].first - g[k - 1].first) + abs(g[k].second - g[k - 1].second);
            sum += diff * diff;
        }
        return sum;
    }

    if (j == g.size())
    {
        int sum = 0;
        int diff = abs(h[i].first - g[j - 1].first) + abs(h[i].second - g[j - 1].second);
        sum += diff * diff;
        for (int k = i + 1; k < h.size(); k++)
        {
            diff = abs(h[k].first - h[k - 1].first) + abs(h[k].second - h[k - 1].second);
            sum += diff * diff;
        }
        return sum;
    }

    if (dp[i][j][onh] != -1)
        return dp[i][j][onh];

    int ans = 1e18;
    if (onh)
    {
        int op1 = abs(h[i].first - h[i - 1].first) + abs(h[i].second - h[i - 1].second);
        int op2 = abs(g[j].first - h[i - 1].first) + abs(g[j].second - h[i - 1].second);
        ans = min(ans, op1 * op1 + f(h, g, i + 1, j, true, dp));
        ans = min(ans, op2 * op2 + f(h, g, i, j + 1, false, dp));
    }
    else
    {
        int op1 = abs(h[i].first - h[j - 1].first) + abs(h[i].second - g[j - 1].second);
        int op2 = abs(g[j].first - g[j - 1].first) + abs(g[j].second - g[j - 1].second);
        ans = min(ans, op1 * op1 + f(h, g, i + 1, j, true, dp));
        ans = min(ans, op2 * op2 + f(h, g, i, j + 1, false, dp));
    }
    return dp[i][j][onh] = ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vp64 h(n), g(m);
    forn(i, n) cin >> h[i].first >> h[i].second;
    forn(i, m) cin >> g[i].first >> g[i].second;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));
    cout << f(h, g, 1, 0, true, dp) << endl;
}

signed main()
{
    freopen("checklist.in", "r", stdin);
    freopen("checklist.err", "w", stderr);
    freopen("checklist.out", "w", stdout);

    ll t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
