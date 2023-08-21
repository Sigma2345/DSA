// https://codeforces.com/problemset/problem/510/C
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
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        for (; j < min(v[i].size(), v[i - 1].size()); j++)
        {
            if (v[i][j] != v[i - 1][j])
            {
                adj[v[i - 1][j] - 'a'].push_back(v[i][j] - 'a');
                indegree[v[i][j] - 'a']++;
                break;
            }
        }
        if(j==min(v[i].size() , v[i-1].size()) && v[i].size() < v[i-1].size()){
            cout << "Impossible" << ln;
            return;
        }
    }

    queue<int> q;
    vector<int> ord;
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        ord.push_back(x);
        // cout << x << endl;
        for (auto y : adj[x])
        {
            indegree[y]--;
            if (indegree[y] == 0)
            {
                q.push(y);
            }
        }
    }

    if (ord.size() != 26)
    {
        cout << "Impossible" << ln;
        return;
    }
    for (int x : ord)
    {
        cout << char(x + 'a');
    }
    // cout << endl;
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
