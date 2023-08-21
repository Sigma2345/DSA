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
ll MOD = 1e9 + 7;
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

int dp[1 << 21][21]; 

int sf(vv32 &mat, int i, int mask){
    if(i==mat.size()){
        return 1; 
    }

    if(dp[mask][i]!=-1) return dp[mask][i]; 

    int ans = 0 ; 
    for (int j = 0; j<mat.size() ; j++){
        if(mat[i][j] && (mask & (1<<j))==0){
            ans = (ans + sf(mat, i+1, mask | (1<<j)))%MOD ; 
        }
    }
    return dp[mask][i] = ans ; 
}

void solve(){

    int n ; 
    cin>>n ;
    memset(dp, -1, sizeof(dp)); 
    vv32 mat(n, v32(n, 0));
    forn(i,n){
        forn(j,n){
            cin>>mat[i][j] ; 
        }
    }
    cout << sf(mat, 0, 0); 
}
signed main()
{
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    t = 1;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
