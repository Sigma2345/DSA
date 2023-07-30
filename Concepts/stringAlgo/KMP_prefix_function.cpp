#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abcabcd";
    int n = s.length();

    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while(j>0 && s[i]!=s[j]){
            j = pi[j - 1]; 
        }
        if(s[i]==s[j]){
            j++; 
        }
        pi[i] = j;
    }

    for (int i = 0; i < n; i++){
        cout<<pi[i]<<' ' ; 
    }
    cout << endl; 

    return 0;
}
