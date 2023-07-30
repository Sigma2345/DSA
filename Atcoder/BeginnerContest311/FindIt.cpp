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

map<int, int> parent;
v32 vis; 

void printPath(int x, int e){
    vector<int> ans; 
    while (x != -1 && x!=e)
    {
        ans.push_back(x);
        x = parent[x];
    }
    ans.push_back(e); 
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end()); 
    for (int y : ans)
        cout << y << ' '; 
    cout << endl;
}

bool cycleFound = false; 

void f(int src, int prev, vv32 &h)
{

    vis[src] = 1;
    parent[src] = prev;
    for (int x : h[src])
    {
        if (vis[x] ==0 ){
            f(x, src, h);
        }
        if(vis[x] == 1 && !cycleFound){
            // cout << "HELLO" << endl; 
            cycleFound = true;
            printPath(src, x);
        }
    }
    vis[src] = 2;
}

void solve()
{

    int n;
    cin >> n;
    vv32 h(n+1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        h[i].push_back(x);
    }
    vis.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
            f(i, -1, h); 
    }
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
