#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<vector<int>> a(5, vector<int>(n));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j]; 
        }
    }
    // std::cout << "--------------------------------" << endl; 
    // now update pairs in each arr
    map<vector<int>, int> mp;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j<n-1;  j++){
            mp[{a[i][j], a[i][j + 1]}]++; 
        }
    }

    // for(auto x: mp){
    //     for(int v: x.first){
    //         std::cout << v << ' '; 
    //     }
    //     std::cout << x.second << endl ;
    // }

    vector<vector<int>> finalPairs;
    unordered_map<int, int> g; 
    for(auto x: mp){
        if(x.second >= 3){
            finalPairs.push_back(x.first);
            g[x.first[0]] = x.first[1];
            // std::cout << x.first[0] << " HELLPO " << x.first[1] << endl;
        }
    }

    // for(auto v: finalPairs){
    //     for(int x: v){
    //         std::cout << x << ' ';
    //     }
    //     std::cout << endl;
    // }
    // std::cout << "--------------------------------" << endl; 

    // find element with freq = 1 
    map<int, int> freq;  
    for(auto v: finalPairs){
        for(int x: v){
            freq[x]++; 
        }
    }

    vector<int> ans; 
    for(auto x: freq){
        if(x.second==1){
            ans.push_back(x.first);
            // std::cout << x.first << endl; 
            break ; 
        }
    }
    for (int i = 0; i < n - 1; i++){
        int x = ans[i];
        ans.push_back(g[x]); 
    }
    // std::cout << "--------------------------------" << endl;

    for(int x: ans){
        std::cout << x << endl; 
    }
    return 0; 
}
