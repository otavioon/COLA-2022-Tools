#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){

	int n,k; cin >> n >> k;
	vector<int> d(k);

	rep(i,k) cin >> d[i];

	for(int i = n; i < 100000; i++){
		int tmp = i;
		set<int> s;

		while(tmp != 0){
			s.insert(tmp%10);
			tmp /= 10;
		}
		bool jud = true;
		
		rep(j,k) if(s.count(d[j])) jud = false;

		if(jud){
			cout << i << endl;
			return 0;
		}
	}
}
    