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
 

void solve(){

    int n;
    cin>>n ;
    v32 odd, even, arr(n); 
    forn(i,n){
        cin >> arr[i]; 
        if(arr[i]%2)
            odd.pb(arr[i]);
        else
            even.pb(arr[i]); 
    }
    sort(begin(odd), end(odd));
    sort(begin(even), end(even));
    int prev = -1, i = 0, j = 0; 
    forn(l,n){
        if(arr[l]%2){
            if(odd[i]<prev){
                cout << "NO" << endl;
                return;
            }
            prev = odd[i++]; 
        }
        else{
            if(even[j]<prev){
                cout << "NO" << endl;
                return;
            }
            prev = even[j++];
        }
    }
    cout << "YES" << endl;
}
int main()
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
