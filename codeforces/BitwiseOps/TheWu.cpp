#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    unordered_map<int, int> sums;
    unordered_map<string, int> mp;
    unordered_map<int, string> maskToString;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }

    for (int i = 0; i <= ((1 << n) - 1); i++)
    {
        string t = "";
        for (int j = 0; j < n; j++)
        {
            t += char(((i & (1 << j)) >> j) + '0') ;
        }
        maskToString[i] = t;
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                s += a[j];
        }
        sums[i] = s;
    }

    for (int i = 0; i < q; i++)
    {
        string ques;
        int k, ans = 0;
        cin >> ques >> k;
        int x = 0;
        for (int j = 0; j < n; j++)
            x += ((ques[j] - '0')<<j);

        for (int j = 0; j <= ((1 << n) - 1); j++)
        {
            int y = ((!(j ^ x)) & ((1 << n) - 1));
            if (sums[y] <= k)
                ans += mp[maskToString[j]];
        }
        cout << ans << endl;
    }
}
int main()
{
    fast_cin();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stderr);
    freopen("output.txt", "w", stdout);

    ll t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
