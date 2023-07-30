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

vector<int> manacher(string &s)
{
    int n = s.length();
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = max(0, min((r - i), p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
            l = i - p[i], r = i + p[i];
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

void solve()
{

    string s;
    cin >> s;

    int n = s.length();
    if (n % 2 == 0)
    {
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans = ans + "#" + s[i];
        }
        ans = ans + "#";
        s = ans;
    }

    s = "$" + s + "^"; 

    vector<int> v = manacher(s);
    int indx = max_element(v.begin(), v.end()) - v.begin() ;
    string ans = "";
    ans += s[indx] ;
    for (int i = 1; i <= v[indx]; i++){
        ans = s[indx-i]!='#' ? s[indx - i] + ans + s[indx + i] : ans ;
    }
    cout << ans << endl; 
}
int main()
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
