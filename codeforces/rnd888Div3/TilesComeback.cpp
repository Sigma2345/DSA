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

bool f(int i, vector<int> &arr, vector<vector<int>> &h, int k)
{
    if (i == arr.size()-1)
        return true;

    bool ans = false;
    int x = arr[i];
    int indx = lower_bound(begin(h[x]), end(h[x]), i) - begin(h[x]);
    for (int j = indx + k - 1; j < h[x].size(); j++){
        for (int l = h[x][j] + 1; l < arr.size() ; l++){
            ans = ans || f(l, arr, h, k); 
        }
    }
    return ans;
}

void solve()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<vector<int>> h(n + 1);
    forn(i, n)
    {
        cin >> arr[i];
        h[arr[i]].pb(i);
    }
    if (f(0, arr, h, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
