#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int G[3][3];
	int sum1=0,sum2=0;
	rep(i,3)rep(j,3) {
		cin >> G[i][j];
		if(i==j) sum1 += G[i][j];
		sum2 += G[i][j];
	}
	if(3*sum1 == sum2) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

  return 0;
}
