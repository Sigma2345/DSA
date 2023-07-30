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

    int n, k;
    cin >> n >> k;
    // cout << k << endl;
    vector<int> pl(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> pl[i];
    }
    vector<vector<int>> a(k + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++)
    {
        int dist = i - a[pl[i]][0] - 1;
        a[pl[i]][0] = i;
        if (a[pl[i]][1] < dist){
            a[pl[i]][2] = a[pl[i]][1]; 
            a[pl[i]][1] = dist;
        }
        else
            a[pl[i]][2] = max(a[pl[i]][2], dist);
    }

    for (int i = 1; i <= k; i++)
    {
        int dist = n - a[i][0];
        a[i][0] = i;
        if (a[i][1] < dist){
            a[i][2] = a[i][1]; 
            a[i][1] = dist;
        }
        else
            a[i][2] = max(a[i][2], dist);
    }

    // for (int i = 1; i <= k; i++)
    // {
    //     cout << a[i][1] << ' ' << a[i][2] << endl;
    // }

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        ans = min(ans, max(a[i][1] / 2, a[i][2]));
    }
    cout << ans << endl;
    // cout << "----------------------" << endl;
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