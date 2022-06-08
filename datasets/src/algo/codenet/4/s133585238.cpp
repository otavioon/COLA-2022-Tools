#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int N,K;
set<int> use;

bool check(int t){
	bool ok = true;
	while(t > 0){
		if(use.count(t%10) == 0){ok = false; break;}
		t /= 10;
	}
	return ok;
}

int main(){
	cin>>N>>K;
	rep(i,10)use.insert(i);
	rep(i,K){
		int t; cin>>t;
		use.erase(t);
	}
	for(int i = N; i<N*100; ++i){
		if(check(i)){cout<<i<<endl; return 0;}
	}
}