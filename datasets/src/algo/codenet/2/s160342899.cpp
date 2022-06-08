#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, a[202020];
bool used[202020];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	
	int cnt = 0;
	for(int i = n-1; i > 0; i--){
		if(used[i]) continue;
		for(i64 j = 1; j < 2*INF; j*=2){
			if(j <= a[i]) continue;
			int pos = lower_bound(a, a+i-1, j-a[i])-a;
			while(a[pos] == j-a[i]){
				if(used[pos]) pos++;
				used[pos] = 1;
				used[i] = 1;
				cnt++;
				break;
			}
			if(used[i]) break;
		}
	}
	cout << cnt << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}