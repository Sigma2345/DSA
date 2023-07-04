#include<bits/stdc++.h>
using namespace std ;

int MOD = 1e9 + 7 ; 

long long int f(int n){
	if(n==0) return 1 ; 
	if(n==1) return 2 ; 


	long long int x = f(n/2) ; 
	x %= MOD ; 
	if(n%2){
		return (x*x*2)%MOD ; 		
	}
	return (x*x)%MOD ; 

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n ; 
	cin>>n ; 

	long long int ans = f(n) ; 
	cout<<ans<<endl ; 

	return 0; 
}