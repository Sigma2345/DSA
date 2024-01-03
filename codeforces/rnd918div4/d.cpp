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
 
bool f(string &s, int i, vector<int> &dp){
    //base case
    if(i==(int)s.length())
        return true; 

    if(dp[i]!=-1)
        return dp[i];

    //recursive case
    bool ans = false; 
    string alpha = "";
    for (int j = i; j<min(i+3, (int)s.length()); j++){
        if(s[j]=='a' || s[j]=='e')
            alpha += "V"; 
        else alpha += "C";
        if(alpha =="CV"){
            // cout<<s.substr(i, j-i+1)<<endl;
            ans = ans || f(s, j+1, dp);
        }
        if (alpha == "CVC")
        {
            // cout << s.substr(i, j - i + 1) << endl;
            ans = ans || f(s, j + 1, dp);
        }
    }
    return dp[i] = ans; 
}

void solve(){

    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<int> dp(n, -1);
    f(s, 0, dp); 
    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    string ans = "";
    for (int i = 0; i < n; i){
        int j = i+1;
        ans += s[i];
        while(j<n && dp[j]!=1){
            ans += s[j];
            j++;
        }
        ans += "."; 
        i = j;
    }
    ans.pop_back();
    cout << ans << endl;
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
