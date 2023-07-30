#include<bits/stdc++.h>
using namespace std ;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n ; 
	cin>>n ; 
	vector<int> arr(n) ; 
	for(int i =0 ; i<n ; i++){
		cin>>arr[i] ; 
	}

	long long int st = 0; 
	for(int i = 1 ; i<n ; i++){
		st += max(0, arr[i-1] - arr[i] ); 
		arr[i] = max( arr[i-1], arr[i] ); 
	}

	cout<<st<<endl ; 

	return 0; 
}