// https://leetcode.com/problems/max-points-on-a-line/description/

#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        if(n==1) return 1 ;
        int maxCnt = 0  ;
        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                int a = -(points[i][1] - points[j][1]) ;
                int b = points[i][0] - points[j][0] ;
                int c = -(a*points[i][0]+b*points[i][1]); 
                
                int cnt = 0 ; 
                for(int k = 0 ; k<n ; k++){
                    int x = points[k][0]*a + points[k][1]*b + c ; 
                    if(x==0){
                        cnt++ ; 
                    }
                }
                
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt ; 
    }
};

// form line equation using 2 points and
// check number of points satisfying that equation 
