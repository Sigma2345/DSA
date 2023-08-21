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

int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811};

int fiblen = sizeof(fib) / sizeof(int); 

void solve(){

    int n, k;
    cin >> n >> k; 

    if(k<=3){
        cout << 1 << endl;
        return; 
    }
    int x = lower_bound(fib, fib + fiblen, n) - fib;
    // cout << "X IS : " << x << endl; 
    if (x < k-1)
    {
        cout << 0 << endl;
        return;
    }
    int cnt = 0;

    x = k - 1;

    if(fib[x-1] == 0){
        cout << 1 << endl;
        return; 
    }

    int lb = n / (fib[x - 1] + fib[x]);
    int ub = n / (fib[x]);

    // cout << lb << ' ' << ub << endl; 

    for (int y = ub/2 ; y <= ub; y++){
        int num = n - fib[x] * y; 
        if(num%fib[x-1] == 0 && num/(fib[x-1]) <= y){
            cnt++; 
        }
    }
    cout << cnt << endl;
    return; 
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
