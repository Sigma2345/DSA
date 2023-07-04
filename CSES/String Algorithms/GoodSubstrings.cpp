// https://codeforces.com/contest/271/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    string s;
    cin >> s;
    map<long long, bool> mp; 
    string b;
    cin >> b; 
    int freq[26] = {0};
    for (int i = 0; i < 26; i++){
        freq[i] = b[i] - '0'; 
    }
    int k;
    cin >> k;
    int ans = 0;
    int n = s.length();
    long long MOD = 1e9 + 9 ;
    long long p = 1; 
    int pow = 31 ; 
    for (int i = 0; i < n; i++){
        long long hash = 0 ;
        p = 1; 
        int cntBadCharacters = 0 ; 
        int freq1[26] = {0};
        for (int j = i ; j < n; j++){
            hash = (hash + (s[j]-'a'+1)*p)%MOD ;
            p = (p * pow) % MOD; 
            freq1[s[j] - 'a']++;
            if(freq[s[j]-'a'] == 0){
                cntBadCharacters++; 
            }
            if(cntBadCharacters<=k && !mp[hash]){
                mp[hash] = true;
                ans++; 
            }
            if(cntBadCharacters > k)
                break; 
            // cout << hash << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
