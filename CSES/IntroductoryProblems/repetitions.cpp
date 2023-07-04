#include<bits/stdc++.h>
using namespace std ;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif


	string s ; 
	cin>>s ; 

	int len = 0; 
	for(int i =0 ; i<s.length() ; ){
		int j = i ; 
		for( ; j<s.length() ; j++){
			if(s[i]!=s[j]){
				break ; 
			}
		}
		// cout<<i<<' '<<j<<endl;   
		len = max(len, (j-i));
		i = j;  
	}
	cout<<len<<endl ; 
	return 0; 
}