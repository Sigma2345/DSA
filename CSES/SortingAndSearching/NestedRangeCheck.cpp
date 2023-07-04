#include<bits/stdc++.h>
using namespace std;

static bool cmp(const vector<int> &p, const vector<int> &q){
    if(p[0]!=q[0])
        return p[0] < q[0];
    return p[1] >= q[1];
}

    int main()
{

    int n;
    cin >> n;

    vector<vector<int>> arr; 

    for (int i = 0; i < n; i++){
        int a, b; 
        cin>>a>>b ;
        arr.push_back({a, b, i});
    }
    sort(arr.begin(), arr.end(), cmp);
    
    
    vector<int> a(n), b(n);
    int maxVal = 0; 
    for (int i = 0; i < n; i++ ){
        if(arr[i][1] <= maxVal)
            b[arr[i][2]] = 1; 
        maxVal = max(maxVal, arr[i][1]); 
    }

    int minVal = INT_MAX;
    for (int i = n - 1; i >= 0; i--){
        if(arr[i][1] >= minVal)
            a[arr[i][2]] = 1;
        minVal = min(arr[i][1], minVal); 
    }

    for (int x : a)
            std::cout << x << ' '; 
    std::cout<<endl ;
    for (int x : b)
        std::cout << x << ' ';

    return 0;
}
