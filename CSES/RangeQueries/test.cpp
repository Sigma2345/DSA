#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main()
{

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    // freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    // #endif

    int n, q;
    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;

    vector<int> pref(n);
    // vector<int> suff(n) ;

    pref[0] = nums[0];
    // suff[n-1] = nums[n-1] ;

    for (int i = 1; i < n; i++)
    {
        pref[i] = nums[i] ^ pref[i - 1];
    }
    // for(int i = n-2 ; i>=0 ; i--){
    // 	suff[i] = nums[i]^suff[i+1];
    // }

    // for(int i = 0 ; i<q ; i++){
    // 	int a, b;
    // 	cin>>a>>b ;
    // 	cout<<a<<' '<<b<<endl ;
    // 	// if(a==1){
    // 	// 	cout<<pref[b-1]<<endl ;
    // 	// }
    // 	// else{
    // 	// 	int x = (pref[b-1]^pref[a-2]) ;
    // 	// 	cout<<x<<endl ;
    // 	// }
    // }

    return 0;
}
