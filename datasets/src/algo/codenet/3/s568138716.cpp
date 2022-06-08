#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define EPS 1e-14

#define all(v) v.begin(),v.end()
#define INF 1<<30
#define mp make_pair
#define pb push_back

#define fi first
#define se second

#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

typedef long long ll;

void solve(){
	int N;
	int A[10010];
	int B[10010];
	int C[10010];
	cin >> N;
	rep(i,N) cin >> A[i];
	rep(i,N) cin >> B[i];
	rep(i,N) cin >> C[i];
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	long long ans = 0;
	rep(i,N){
		int ca = 0;
		int cb = 0;

		while(ca < N && A[ca] < B[i]){
			ca++;
		}
		while(cb < N && C[cb] <= B[i]){
			cb++;
		}
		ans += ca * (N-cb);

	}
	cout << ans << endl;
}

int main(){
	// while(1){
		solve();
	// }
	return 0;
}