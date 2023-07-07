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

    int n, m, total;
    cin >> n >> m >> total;

    vp32 arr;
    pair<int, int> rudolph;
    for (int i = 0; i < n; i++)
    {
        int time_used = 0;
        int penalty = 0, cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        while (!pq.empty() && (time_used + pq.top()) <= total)
        {
            penalty += time_used + pq.top();
            time_used += pq.top();
            cnt++;
            pq.pop();
        }
        arr.push_back({cnt, penalty});
        if (i == 0)
            rudolph = {cnt, penalty};
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first == b.first ? a.second < b.second : a.first > b.first; });

    for (int i = 0; i < n; i++)
    {
        if (arr[i].first == rudolph.first && arr[i].second == rudolph.second)
        {
            cout << (i + 1) << endl;
            return;
        }
    }
    return;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
