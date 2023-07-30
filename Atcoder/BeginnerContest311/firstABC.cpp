#include <bits/stdc++.h>  
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[3] = {0};
    int i = 0;
    for (; i < n && !(arr[0] && arr[1] && arr[2]); i++)
    {
        arr[s[i] - 'A']++;
    }
    cout << i << endl;
}
int main()
{
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

    int t;
    t =1;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
