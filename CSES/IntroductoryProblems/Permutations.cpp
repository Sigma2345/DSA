#include<bits/stdc++.h>
using namespace std ;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n ; 
	cin>>n ; 

	if(n==1){
		cout<<1<<endl; 
		return 0 ; 
	}

	if(n==2 || n==3){
		cout<<"NO SOLUTION"<<endl ;
		return 0; 
	}  

	if(n==4){
		cout<<2<<' '<<4<<' '<<1<<' '<<3<<endl ; 
		return 0 ; 
	}

	for(int i = 1 ; i<=n ; i+=2) cout<<i<<' '  ;
	for(int i = 2 ; i<=n ; i+=2) cout<<i<<' '  ;

	cout<<endl ; 

	return 0; 
}