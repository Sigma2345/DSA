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
 
bool f(v32 &s, v32 &b, int x){
    int indx1 = upper_bound(begin(s), end(s), x) - begin(s);
    int indx2 = lower_bound(begin(b), end(b), x) - begin(b);

    int cnt1 = indx1  ;
    int cnt2 = b.size() - indx2;

    return cnt2 <= cnt1; 
}

void solve(){

    int n, m;
    cin >> n >> m;
    v32 s(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int j = 0; j < m; j++){
        cin >> b[j]; 
    }

    sort(begin(s), end(s));
    sort(begin(b), end(b));

    int st = 0, e = b[m - 1]+1 , ans = -1; 
    while(st<=e){
        int mid = st + (e - st) / 2;   
        if(f(s, b, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            st = mid+1; 
        }
    }
    cout << ans << endl;
}
int main()
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
