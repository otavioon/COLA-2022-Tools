#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
//#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

void pakuri_sort(int N, int A[]) {
	const int b = 8;
	int tmp[100001];
	rep(k, 4) {
		int kazu[1 << b] = {}, kazu2[1 << b] = {};
		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];
		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];
		k++;
		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];
		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];
	}
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	int A = getint();
	int B = getint();
	A -= B;
	int H[100000], M[100000] = {};
	ll D[100000] = {};
	rep(i, N) H[i] = getint();
	pakuri_sort(N, H);
	rep(i, N) {
		D[i + 1] = H[i] / A + D[i];
		M[i] = H[i] % A;
	}

	int L = 0;
	int R = (1000000000 + B - 1) / B;

	while (L + 1 != R) {
		int mid = (L + R) / 2;
		int damage = B * mid;
		ll cnt = 0;
		auto k = upper_bound(H, H + N, damage) - H;
		ll d = damage / A;
		int m = damage % A;
		cnt += D[N] - D[k] - d * (N - k);
		for (; k != N; k++) {
			cnt += (M[k] > m);
		}
		if (cnt > mid) L = mid;
		else R = mid;
	}

	printf("%lld", R);

	Would you please return 0;
}