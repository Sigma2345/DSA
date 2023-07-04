#include<bits/stdc++.h>
using namespace std ;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif


	int n, q ;
	cin >> n >> q; 
	vector<int> nums(n) ;
	for(int &x: nums) cin>>x ; 

	vector<int> pref(n) ;

	pref[0] = nums[0] ;

	for(int i =1 ; i<n ; i++){
		pref[i] = nums[i]^pref[i-1] ; 
	}


	for(int i = 0 ; i<q ; i++){
		int a, b;  
		cin>>a>>b ;
		if(a==1){
			cout<<pref[b-1]<<endl ; 
		}		
		else{
			int x = (pref[b-1]^pref[a-2]) ; 
			cout<<x<<endl ; 
		}
	}


	return 0 ; 
}
