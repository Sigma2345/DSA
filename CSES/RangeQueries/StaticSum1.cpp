// https://cses.fi/problemset/task/1646
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<stack>
#include<map>
#define ll long long int
using namespace std ;


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif


	int n, q ; 
	cin>>n>>q ;

	vector<ll> v(n) ; 
	for(ll &x: v) cin>>x ; 

	v.insert(v.begin(), 0); 
	for(int i =1 ; i<=n ; i++) v[i] = v[i] + v[i-1] ; 
	// for(int x: v) cout<<x<<' ' ; 
	cout<<endl ;
	for(int i = 0 ; i<q ; i++){
		int a, b ; 
		cin>>a>>b ; 
		cout<<(v[b]-v[a-1])<<endl; 
	}

	return 0 ; 
}