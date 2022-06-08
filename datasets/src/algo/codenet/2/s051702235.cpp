#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define eps DBL_EPSILON
#define moder 10007
#define int long long
#define ll long long
#define INF LLONG_MAX/3
#define P std::pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
int n,a;
multiset<int> st;
int func(int x){
	int s=1;
	while(s<=x)s*=2;
	return s;
}
signed main(){
	cin>>n;
	rep(i,n){
		cin>>a;
		st.insert(a);
	}
	int ans=0;
	while(st.size()>1){
		auto x=*st.rbegin();
		st.erase(--st.end());
		auto it=st.find(func(x)-x);
		if(it!=st.end()){
			st.erase(it);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}