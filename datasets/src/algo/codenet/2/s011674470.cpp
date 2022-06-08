#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int N,ans = 0;
multiset<int> A;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	REP(i,N){
      	int x;
		cin >> x;
      	A.insert(x);
	}

	while(A.size() > 1){
		int x = *prev(A.end());
		A.erase(prev(A.end()));
		int d = 1;
		while(d <= x){
			d = d << 1;
		}
		if(A.find(d - x) != A.end()){
			ans++;
			A.erase(A.find(d - x));
		}
	}

	cout << ans << endl;

}
