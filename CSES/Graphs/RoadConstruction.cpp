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

int numComp;
int maxSize; 

int get(int a, v32 &p){
    return p[a]==-1 ? a : p[a] = get(p[a], p); 
}

void union_dsu(int b, int a, v32 &p, v32 & sz)
{
    int x = get(a, p), y = get(b, p); 
    if(x==y)
        return; 

    if(x>y) swap(x, y);
    numComp--;
    p[y] = x;
    sz[x] += sz[y];
    maxSize = max(maxSize, sz[x]);
}
    void solve()
{

    int n, m; 
    cin>>n>>m ;
    numComp = n, maxSize = 1; 
    v32 p(n + 1, -1);
    v32 s(n+1, 1);
    forn(i, m){
        int x, y; 
        cin>>x>>y ;
        union_dsu(x, y, p, s);
        cout << numComp << ' ' << maxSize << endl; 
    }
}
int main()
{
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    t =1 ; 
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
