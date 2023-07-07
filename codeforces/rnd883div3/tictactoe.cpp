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

char sym[3] = {'X', 'O', '+'};
char arr[3][3];

void solve()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    for (int col = 0; col < 3; col++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[0][col] == arr[1][col] && arr[1][col] == arr[2][col] && arr[2][col] == sym[j])
            {
                cout << sym[j];
                return;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][0] == arr[i][1] && arr[i][2] == arr[i][1] && arr[i][0] == sym[j])
            {
                cout << sym[j];
                return;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == sym[j])
        {
            cout << sym[j];
            return;
        }
        if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] == sym[j])
        {
            cout << sym[j];
            return;
        }
    }

    cout << "DRAW";
}
signed main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
        cout << endl;
    }
    return 0;
}
