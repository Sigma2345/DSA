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

v32 p; 

int get(int x){
    return p[x] == -1 ? x : p[x] = get(p[x]) ; 
}

void merge(int x, int y){
    x = get(x), y = get(y); 
    if(x==y)
        return;
    if(x>y)
        swap(x, y);
    p[y] = x;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    p.resize(n + 1, -1);
    v32 time(n + 1, -1); 
    vp32 holders(n + 1, {-1, -1}), ogconfig(n + 1, {-1, -1});
    // also mantain who was holding who -> holders -> <l,r>
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y; 
        if (x != -1)
        {
            holders[i].first = ogconfig[i].first = x;
        }
        if (y != -1)
        {
            holders[i].second = ogconfig[i].second = y;
        }
    }
    vp32 inst(m);
    for (int i = 0; i < m; i++)
    {
        cin >> inst[i].first >> inst[i].second;
        if (inst[i].second == 1)
            holders[inst[i].first].first = -1;
        else
            holders[inst[i].first].second = -1;
    }
    for (int i = 1; i <= n; i++){
        if(holders[i].first != -1 )
            merge(i, holders[i].first);
        if (holders[i].second != -1)
            merge(i, holders[i].second); 
    }
    for (int i = m - 1; i >= 0; i--){
        int x; 
        if (inst[i].second == 1){
            x = ogconfig[inst[i].first].first; 
        }
        else{
            x = ogconfig[inst[i].first].first ;
        }
        if(p[x]==-1 && x!=1){
            time[x] = i; 
        }
        merge(x, inst[i].first); 
        
    }

    for (int i = 1; i<=n ; i++)
        cout << time[i] << endl; 
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
