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
    setprecision(12);
    double n, b, h;
    cin >> n >> b >> h;

    v32 bases(n);
    for (int i = 0; i < n; i++)
        cin >> bases[i];
    sort(bases.begin(), bases.end());

    double ans = 0.0000;
    for (int i = 0; i < n - 1; i++)
    {
        double sum;
        if (bases[i] + h > bases[i + 1])
        {
            double dist = (bases[i + 1] - bases[i]) * 1.000000;
            double smallerHeight = (bases[i] + h - bases[i + 1])*1.00000; 
            double smallerSide = (b * 1.0) * ( smallerHeight / (h * 1.0));
            sum = 0.5 * (smallerSide + b) * dist;
            ans += sum;
        }
        else
        {
            sum = b * 0.5 * h;
            ans += sum;
        }
        // cout << setprecision(12) << sum << endl;
    }
    double sum = 0.5 * b * h;
    ans += sum;
    // cout << setprecision(12) << sum << endl; 
    cout << setprecision(12) << ans << endl;
    // cout << "------------------------------" << endl;
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
