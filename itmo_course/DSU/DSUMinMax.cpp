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

int get(int x, vector<int> &p)
{
    return p[x] == -1 ? x : p[x] = get(p[x], p);
}

void union_dsu(int x, int y, vector<int> &p, vector<pair<pair<int, int>, int>> &minmax)
{
    int a = get(x, p), b = get(y, p);
    if (a == b)
        return;
    if (a > b)
        swap(a, b);
    p[b] = a;
    minmax[a].first.first = min(minmax[a].first.first, minmax[b].first.first);
    minmax[a].first.second = max(minmax[a].first.second, minmax[b].first.second);
    minmax[a].second += minmax[b].second;
}

void solve()
{

    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1);
    vector<pair<pair<int, int>, int>> minmax(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = -1;
        minmax[i] = {{i, i}, 1};
    }
    forn(i, q)
    {
        string s;
        int x, y;
        cin >> s;
        if (s == "union")
        {
            cin >> x >> y;
            union_dsu(x, y, p, minmax);
        }
        else
        {
            cin >> x;
            y = get(x, p);
            cout << minmax[y].first.first << ' ' << minmax[y].first.second << ' ' << minmax[y].second << endl;
        }
    }
}
int main()
{

    fast_cin();
    ll t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
