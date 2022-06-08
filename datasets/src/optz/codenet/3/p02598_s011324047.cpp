#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// *st.find_by_order(index), 0-based
// order_of_key(e)

ll eval(ll x, vector<ll> &A) {
	ll ret=0;
	for (auto a : A)
		ret+=(a+x-1)/x-1;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,K; cin>>N>>K;
	vector<ll> A(N);
	for (int i=0; i<N; i++)
		cin>>A[i];
	ll low=0, high=1e9+7;
	while(low<high) {
		int mid=(low+high)/2;
		if(eval(mid,A)<=K) high=mid;
		else low=mid+1;
	}
	cout<<min(*max_element(A.begin(),A.end()),high)<<"\n";
	return 0;
}