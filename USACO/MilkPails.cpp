#include <bits/stdc++.h>
#include <complex>
#include <iomanip>
#include <fstream>

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
#define int long long

void solve()
{

    int x, y, k, m;
    cin >> x >> y >> k >> m;

    vector<vector<int>> dist(x + 1, vector<int>(y, INF));
    queue<pair<int, int>> q;
    q.push({0, 0});
    int ndist = 0;

    while (!q.empty() && ndist <= k+1)
    {
        int s = q.size();
        for (int k = 0; k < s; k++)
        {
            auto t = q.front();
            q.pop();
            dist[t.first][t.second] = ndist;
            int i = t.first, j = t.second;
            int sx[] = {x, 0, i, 0, min(i + j, x), max( i + j - y, (long long) 0)};
            int sy[] = {0, y, 0, j, max( i + j - x, (long long) 0 ), min(i + j, y)};

            for (int l = 0; l < 6; l++){
                if(dist[sx[l]][sy[l]]!=INF)
                    continue;
                dist[sx[l]][sy[l]] = ndist + 1;
                q.push({sx[l], sy[l]}); 
            }
        }

        ndist++;
    }

    int ans = INF; 
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= x; j++){
            if(dist[i][j]<=k) ans = min(ans, abs(i+j-m));  
        }
    }
    cout << ans << endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
#endif

    fast_cin();
    ll t;
    t=1 ;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
