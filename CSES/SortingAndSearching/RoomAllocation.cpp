#include<bits/stdc++.h>
using namespace std;
int main(){
 
    int n ;
    std::cin >> n;

    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;

        while (!s.empty() && (s.top().first > b || s.top().second < a))
        {
            s.pop();
        }
        s.push({a, b});
        std::cout << s.size() << ' '; 
    }



    return 0; 
}
