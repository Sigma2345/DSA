#include<bits/stdc++.h>
using namespace std;
int main(){
 
    int n, d; 
    cin>>n>>d ;

    vector<int> v(d, 0); 
    for(int i = 0; i<n ; i++){
        string s;
        cin >> s;
        for (int j = 0; j<d ; j++){
            if(s[j]=='x') v[j] = 1; 
        }
    }
    int ans = 0; 
    for(int i = 0; i<d ; ){
        if(v[i] == 0){
            int cnt = 0; 
            while(i<d && v[i] == 0)
                cnt++, i++;
            ans = max(ans, cnt); 
        }
        else{
            i++; 
        }
    }
    cout << ans << endl; 

    return 0; 
}
