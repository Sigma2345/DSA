// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t; 

    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; i++){
            cin>>v[i].first>>v[i].second; 
        }
        sort(v.begin(), v.end());
        ordered_set s;
        long long ans = 0;
        for (int i = n-1; i >=0; i--){
            // cout<<"--------"<<s.order_of_key(v[i].second+1)<<endl;
            ans += s.order_of_key(v[i].second+1);
            s.insert(v[i].second);
        }
        cout << (ans) << endl;
    }
}
