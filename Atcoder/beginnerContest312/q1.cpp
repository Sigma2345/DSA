#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    cin >> s;
    string arr[7] = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    for (int i = 0; i < 7; i++){
        if(arr[i] == s){
            cout<<"Yes"<<endl;
            return 0; 
        }
    }
    cout << "No" << endl; 

    return 0;
}
