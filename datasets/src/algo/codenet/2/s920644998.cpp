#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

int main(){	
	long long N;
	scanf("%lld",&N);
	ll A;
	multiset<ll> st;
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A);
		st.insert(A);
	}
	ll res = 0;
	while(!st.empty()) {
		ll maxA = *st.rbegin();
		// cout << maxA << endl;
		ll two = 2;
		while (two <= maxA) two *= 2;
		// cout << *st.find(maxA) << endl;
		st.erase(st.find(maxA));
		// cout << two-maxA << " " << *st.find(two-maxA) << endl;
		if (st.find(two-maxA) != st.end()) {
			res++;
			st.erase(st.find(two-maxA));
		}
	}
	cout << res << endl;	

	return 0;
}

