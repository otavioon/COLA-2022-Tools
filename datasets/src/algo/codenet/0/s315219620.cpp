#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	int K;
	cin >> S >> K;
	int N = S.length();
	cat ans = 0;
	for(int i = 0; i < N; i++) if(i == 0 || S[i] != S[i-1]) {
		int r = i;
		while(r < N && S[r] == S[i]) r++;
		if(S[0] == S[N-1]) if(i == 0 || r == N) continue;
		ans += 1LL * ((r-i) / 2) * K;
	}
	if(S[0] == S[N-1]) {
		bool eq = true;
		for(int i = 0; i < N; i++) if(S[i] != S[0]) eq = false;
		if(eq) ans = (1LL*K*N)/2;
		else {
			int nl = 0, nr = 0;
			while(S[nl] == S[0]) nl++;
			while(S[N-1-nr] == S[0]) nr++;
			ans += nl/2;
			ans += nr/2;
			ans += 1LL * ((nl+nr)/2) * (K-1);
		}
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
