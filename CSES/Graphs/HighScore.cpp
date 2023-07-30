#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std ;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n, m ; 
	cin>>n>>m ; 

	// since we need to take maximum score reverse the path weights 
	// and calculate minimum weight possible
	vector<vector< pair<int, int> > > v(n+1) ;
	for(int i = 0 ; i<m ; i++){
		int x, y, dist ; 
		cin>>x>>y>>dist ; 
		v[x].push_back({y, -dist}); 
	} 

	vector<int> distFromSrc(n+1, INF) ;
	distFromSrc[1] = 0 ; 
	for(int i = 1 ; i<=n ; i++){
		for(int j = 1; j<=n ; j++){
			for(int k =0; k < v[j].size() ; k++){
				int dist1 = v[j][k].second, node2 = v[j][k].first ;
				if(distFromSrc[node2] > distFromSrc[j] + dist1){
					distFromSrc[node2] = distFromSrc[j] + dist1 ;
					cout<<j<<' '<<node2<<' '<<distFromSrc[node2]<<endl ; 
				} 
			}
		}
	}

	// negative cycle
	
	for(int j = 1; j<=n ; j++){
		for(int k =0; k < v[j].size() ; k++){
			int dist1 = v[j][k].second, node2 = v[j][k].first ;
			if(distFromSrc[node2] > distFromSrc[j] + dist1){
				cout<<-1<<endl ; 
				return 0;  
			} 
		}
	}
	


	int maxDist = 0 ; 
	for(int i =1 ; i<=n ; i++){
		maxDist = maxDist + distFromSrc[i] ; 		
	}

	cout<<(-maxDist)<<endl ; 

	return 0 ; 
}
