#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(obj)   (obj).begin(),(obj).end()

#define debug(var)  do{std::cout << __LINE__ << "> " << #var << ": ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

void Main() {
	int N, K; cin >> N >> K;
	set<int> st;
	REP(i, K) {
		int d; cin >> d;
		st.insert(d);
	}
	REP(i, 10000) {
		if (i < N) continue;
		int tmp = i;
		bool flag = true;
		while (tmp > 0) {
			int n = tmp % 10;
			if (st.find(n) != st.end()) {
				flag = false;
				break;
			}
			tmp /= 10;
		}
		if (flag) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
