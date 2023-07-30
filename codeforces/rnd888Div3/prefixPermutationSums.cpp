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
#define int long long

void solve()
{

    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }

    vector<int> v(n - 1, a[0]);
    for (int i = 1; i < n - 1; i++)
    {
        v[i] = a[i] - a[i - 1];
    }

    int total = (n * (n + 1)) / 2;
    if (total < a[n - 2])
    {
        cout << "NO" << endl;
        return;
    }

    else if (total == a[n - 2])
    {
        sort(v.begin(), v.end()); 
        int sum = 0, miscnt = 0;
        unordered_map<int, int> mp; 
        for(int x: v)
            mp[x]++;

        int sumMis = 0; 
        for (int i = 1; i <= n; i++)
        {
            if(mp[i]==0)
                sum += i, miscnt++;
            if(mp[i]==2) sumMis = i;
        }

            if (miscnt > 2)
            {
                cout << "NO" << endl;
                return;
            }
            else if (sumMis == sum)
            {
                cout << "YES" << endl;
                return;
            }

            else{

        }
    }

    else
    {
        // either last element missing or NO
        int diff = total - a[n - 2];
        sort(begin(v), end(v));
        int misCnt = 0;
        int i = 0, misNum = 0;
        for (int l = 1; l <= n; l++)
        {
            if (l != v[i])
                misNum = l, misCnt++;
            else
                i++;
        }

        if (misCnt > 1)
        {
            cout << "NO" << endl;
            return;
        }

        if (diff == misNum)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return; 
    }
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
