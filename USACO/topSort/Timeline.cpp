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

    int n, m, c;
    cin >> n >> m >> c;

    v32 arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<vector<pair<int, int>>> h(n + 1), backEdge(n + 1);
    v32 indeg(n + 1, 0);
    for(int i =0 ; i<c ; i++){
        int x, y, z;
        cin >> x >> y >> z; 
        h[x].pb({y,z}); 
        backEdge[y].pb({x,z});
        indeg[y]++; 
    }
    v32 ord;
    v32 ans(n + 1, 0);
    queue<int> q; 
    for (int i = 1; i <= n; i++) if(indeg[i]==0) q.push(i); 
    while(!q.empty()){
        auto x = q.front();
        q.pop(); 
        ord.pb(x); 
        for(auto y: h[x]){
            indeg[y.first]--; 
            if(indeg[y.first] == 0 )
                q.push(y.first); 
        }
    }

    for (int i = 0; i<ord.size() ; i++){
        int x = ord[i];
        // cout << ord[i] << ' '; 
        ans[x] = max(ans[x], arr[x]);
        for(auto y: backEdge[x]){
            ans[x] = max(ans[x], ans[y.first] + y.second);
            // cout << "HE" << endl;
        }
    }
    cout << endl; 
    for (int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
}
int main()
{
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    fast_cin();
    ll t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
