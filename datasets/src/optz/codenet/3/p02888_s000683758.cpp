 #include "bits/stdc++.h"

using namespace std;

#define sp(x) cout<<setprecision(x);
#define all(a) (a).begin(), (a).end()
#define inf 10000000
#define linf INT64_MAX*0.99
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define yes "Yes"
#define no "No"
#define divs 1000000007
#define dive 1000000009

typedef pair<int, int> P;

int n; 
vector<int> l;
bool isOK(int index, int key){
	if(l[index] >= key) return true;
	else return false;
}
int binary_search(int key){
	int ng = -1;
	int ok = (int)l.size();

	while(abs(ok-ng)>1){
		int mid = (ok + ng) /2;

		if(isOK(mid,key)) ok = mid;
		else ng = mid;
	}
	return ok;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	l.resize(n);
	REP(i,n) cin>>l[i];
	sort(all(l));
	int ans = 0;
	REP(i,n-1){
		FOR(j,i+1,n){
			int a = l[i];
			int b = l[j];
			int left = binary_search(max(a-b,b-a)+1);
			int right = binary_search(a+b);
			if(left<=i&&i<right) ans--;
			if(left<=j&&j<right) ans--;
			ans += right - left;
		}
	}
	cout<<ans/3<<endl;
    return 0;
}