#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S; cin >> S;
	string T;
	int K; cin >> K;
	if ((int)S.length() * K <= 20000000) {
		string C;
		rep(i, K) C += S;
		int len = (int)S.length() * K;
		int cnt = 0;
		rep(i, len - 1) {
			if (C[i] == C[i + 1]) {
				cnt++;
				i++;
			}
		}
		cout << cnt << endl;
		return 0;
	}
	int cycle = 360 * (int)S.length();
	rep(i, cycle) T += S;
	int len = T.length();
	int cnt1 = 0;
	int i = 0;
	if (K / cycle >= 1) {
		for (i = 0; i < len; i++) {
			if (i == len - 1) {
				if (T[0] == T[len - 1]) {
					cnt1++;
					i++;
				}
			}
			else if (T[i] == T[i + 1]) {
				cnt1++;
				i++;
			}
		}
	
	}
	//dump(i);
	//dump(len);
	int move = 0;
	if (K / cycle >= 1 && i < len) move++;
	string R;
	//dump(cycle);
	int t = K % cycle;
	if (K / cycle >= 1) t += cycle;
	rep(i, t) R += S;
	len = R.length();
	//dump(len);
	int cnt = 0;
	rep(i, len - 1) {
		if (i == 0 && move) {
			if (R[0] == R[len - 1]) cnt++;
			i++;
		}
		else if (R[i] == R[i + 1]) {
			cnt++;
			i++;
		}
	}
	//dump(cnt1);
	//dump(cnt);
	cout << cnt1 * ((K / cycle) - 1) + cnt << endl;

	return 0;
}
