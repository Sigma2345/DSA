// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int MOD = 1e9 + 7 ; 

int main()
{

    ll n ;
    cin>>n ; 
    vector<ll> arr(n + 1, 1);
    for (int i = 1; i <= n; i++){
        arr[i] = 0 ; 
        for (int j = 1; j <= 6 && j <= i; j++){
            arr[i] = (arr[i] + arr[i-j])%MOD ;
        }
    }

    cout << arr[n]<< endl ; 

    return 0;
}
