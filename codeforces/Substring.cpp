// https://codeforces.com/contest/919/problem/D
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vv32 dp(n+1, v32(26, 0));
    vector<int> indeg(n + 1, 0);
    string s;
    cin >> s;
    s = "$" + s;
    forn(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        indeg[y]++;
    }

    // check cycle
    vector<int> ord;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            // cout<<"CFNVHIJKSDBCVS"<<endl ; 
            q.push(i);
            dp[i][s[i] - 'a'] = 1;
        }
    }
    // cout << "BFIDF" << endl;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ord.pb(x);
        for (int y : adj[x])
        {
            indeg[y]--;
            for (int j = 0; j < 26; j++)
            {
                dp[y][j] = max(dp[y][j], dp[x][j] + (s[y] - 'a' == j));
            }
            if (indeg[y] == 0)
                q.push(y);
        }
    }
    if (ord.size() < n)
    {
        cout << -1 << ln;
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
