/************
* 	@Just Another Source code by: ankit.sangwan1999
*	@created on: 10 Sept 2020
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) //;cout.tie(NULL)
#define ll long long
const int mod = 1e9+7;
const long double pie = 3.14159265358979323846;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, ll> ma; // orderd_map using pb_ds


bool fun(int *arr, int n, int k, int mid){
	int ops = 0;
	for(int i=0;i<n;i++){
		ops += (arr[i]-1)/mid;		
		if(ops > k) return 0;
	}
	return 1;
}

void solve(){

	int n, k; cin>>n>>k;
	int ma = INT_MIN;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ma = max(ma, arr[i]);
	}
	
	int high = ma;
	int low = 1;
	int mid = (low + high)/2;
	int ans;
	while(low<=high){

		if(fun(arr, n, k, mid)){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
		mid = (low + high)/2;
	}

	cout<<ans<<endl;

}

signed main(){

	#ifndef ONLINE_JUDGE
    freopen("/mnt/DATA/D_Drive/CP/input.txt", "r", stdin);
    freopen("/mnt/DATA/D_Drive/CP/output.txt", "w", stdout);
    #endif

    fastio;
    int t=1;
    // cin>>t;

    while(--t>=0){
    	solve();
    }
		

    return 0;
}