// https://cses.fi/problemset/task/1648
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<stack>
#include<map>
using namespace std ;
#define ll long long int

vector<ll> segTree ; 

void buildTree(vector<int> &arr,  int v, int tl, int tr ){
	if(tl==tr){
		segTree[v] = arr[tl] ; 
		return ; 
	} 
	int mid = tl + (tr-tl)/2  ;
	buildTree(arr, 2*v+1, tl, mid); 
	buildTree(arr, 2*v+2, mid+1, tr); 
	segTree[v] = min(segTree[2*v+1] , segTree[2*v+2]); 
}

ll f(int v, int tl , int tr, int l, int r){
    if (l>r) return INT_MAX ; 
    if(l==tl && r==tr) return segTree[v] ;
    int mid = tl + (tr - tl) / 2;
    return min(f(v*2+1, tl, mid, l, min(r, mid)) , f(v*2 + 2, mid+1, tr, max(l, mid+1), r)) ; 
}

void update(int v, int tl, int tr, int pos, int new_val){

    if(tl==tr){
        segTree	[v] = new_val;
        return; 
    }

    //recursive case
    int mid = tl + (tr-tl)/2 ; 
    if(pos <= mid) update(2*v+1, tl, mid, pos, new_val);
    else update(2*v+2, mid+1, tr, pos, new_val);
    segTree	[v] = min(segTree[2*v+1] , segTree[2*v+2]); 
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif

	int n, q; 
	cin>>n>>q ;

	vector<int> v(n) ;
	for(int &x: v) cin>>x ; 

	segTree.resize(4*n+1, INT_MAX) ; 
	// cout<<"Hello"<<endl; 
	buildTree(v, 0, 0, n-1);

	// for(int x: segTree) cout<<x<<' ' ; 
	// cout<<endl ; 
	for(int i =0 ; i<q ; i++){
		int inst, a, b ;
		cin>>inst>>a>>b ; 
		if(inst==2) {
			// cout<<"Hello"<<endl ;
			cout<<f(0, 0, n-1, a-1, b-1)<<endl ; 
		}
		else 
			update(0, 0, n-1, a-1, b); 
	} 


	return 0 ; 
}