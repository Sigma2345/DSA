#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds; 
using namespace std; 

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<int> s; 

int main() {

	int n, k; 
	cin>>n>>k ; 

	for(int i = 1;  i<=n ; i++) s.insert(i) ; 
	int pos = 0; 
	while(s.size() > 1){
		pos = (pos + k) % s.size(); 
		cout<<(*s.find_by_order(pos))<<' ' ;
		s.erase(*(s.find_by_order(pos)));
		pos = pos % s.size(); 
	}
	cout << (*s.find_by_order(0)) << endl;

	return 0; 
}
