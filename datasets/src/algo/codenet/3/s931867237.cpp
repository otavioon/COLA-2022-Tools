#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define co(x) cout << (x) << "\n"
#define ll long long
#define pb push_back
#define Never
#define To

using namespace std;

int main(){

	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;

	cin >> N;

	ll A[N], B[N], C[N];

	for(ll l = 0; l < N; l++){
		cin >> A[l];
	}

	for(ll l = 0; l < N; l++){
		cin >> B[l];
	}

	for(ll l = 0; l < N; l++){
		cin >> C[l];
	}

	sort(A, A+N);
	sort(B, B+N);
	sort(C, C+N);

	ll ans = 0;
	for(ll b = 0; b < N; b++){

		ll ok = -1;
		ll ng = N;

		while(ng - ok > 1){
			ll mid = (ok + ng)/2;

			if(A[mid] < B[b]) {
				ok = mid;
			} else {
				ng = mid;
			}
		}

		ll a = ok + 1;

		ok = N;
		ng = -1;
		while(ok - ng > 1){

			ll mid = (ok + ng)/2;

			if(C[mid] <= B[b]) {
				ng = mid;
			} else {
				ok = mid;
			}
		}
		ll c = N - ok;

		ans += a * c;

	}

	cout << ans << endl;

	Never To return 0;
}
