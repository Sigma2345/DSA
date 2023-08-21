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

void solve(){
    int n;
    cin >> n;
    vv32 a(n); 
    forn(i, n){
        int x;
        cin >> x;
        forn(j,x){
            int y;
            cin >> y;
            a[i].push_back(y); 
        }
    }
    forn(i,n){
        sort(all(a[i]));
    }
    if(n==1){
        cout << a[0][0] << endl ; 
        return;
    }

    sort(all(a));
    int minElement = INT_MAX;
    for (int i = 0; i<n; i++)
    {
        minElement = minElement > a[i][1] ? a[i][1] : minElement;
    }
    int ans = a[0][0] + a[0][1] ;
    for (int i = 1; i < n; i++) ans += a[i][1];
    cout<<ans-minElement<<endl;
}
signed main()
{
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}