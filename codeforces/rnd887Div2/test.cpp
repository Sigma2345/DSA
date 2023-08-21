#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

    int a = 0, b = 1;
    for (int i = 2; i < 100 && b <= 300000; i++){
        cout << i << " : " << (a + b) << endl;
        int c = a + b;
        a = b;
        b = c; 
    }

        return 0; 
}
