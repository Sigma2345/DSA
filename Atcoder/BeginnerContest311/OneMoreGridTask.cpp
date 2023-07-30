// https://atcoder.jp/contests/abc311/tasks/abc311_g
#include <bits/stdc++.h>  
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define int long long 
#define MAXN 300

void build(int v, int tl, int tr, vv32 &t, v32 &mat, int i){
    if(tl>tr)
        return;
    if (tl == tr){
        t[i][v] = mat[tl];
    }

    int mid = (tl + tr) / 2; 
    build(2*v, tl, mid, t, mat, i);
    build(2 * v+1, mid+1, tr, t, mat, i);
    t[i][v] = max(t[i][2 * v], t[i][2 * v + 1]); 
}

int query(int v, int tl, int tr, int l, int r, vv32 &t, int i){
    if (l > r || l > tr || r < tl)
        return INT_MAX;

    if(l>=tl && r<=tr)
        return t[i][v]; 

    int mid = (tl + tr) / 2;
    return min(query(2 * v, tl, mid, l, min(r, mid), t, i), query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, t, i)); 
}

void solve()
{

    int n, m;
    cin >> n >> m;
    vv32 t(n+1, v32(4 * MAXN));
    vv32 mat(n + 1, v32(m + 1)), sumOfMat(n + 1, v32(m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> mat[i][j]; 
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            sumOfMat[i][j] = sumOfMat[i - 1][j] + sumOfMat[i][j - 1] - sumOfMat[i - 1][j - 1]; 
        }
    }

    for (int i = 1; i <= n; i++){
        build(1, 1, m, t, mat[i], 1);
    }

    int ans = 0; 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++){
            for (int k = 0; k <= min(i, j); k++){
                
            }
        }
    }

    cout << ans << endl;
}
signed main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
