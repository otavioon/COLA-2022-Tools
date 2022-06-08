#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <cmath>
#include <limits>
#include <bitset> 
#include <iterator> 
#include <map>
#include <queue>
#include <set>
#define rep(i,n) for(ll i=0;i<(n); ++i)
#define per(i,n) for(ll i=n-1;i>=0; --i)
#define all(x) (x).begin(),(x).end()
#define _GLIBCXX_DEBUG
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
typedef long long ll;
ll MOD = 1000000007;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<vector<ll>>c(3, vector<ll>(3));
	rep(i, 3) {
		rep(k, 3) {
			cin >> c[i][k];
		}
	}
	rep(i, 101) {
		rep(j, 101) {
			rep(k, 101) {
				if ((c[0][0] - i == c[1][0] - j) &&(c[0][0] - i == c[2][0] - k)) {
					if ((c[0][1] - i == c[1][1] - j) && (c[0][1] - i == c[2][1] - k)) {
						if ((c[0][2] - i == c[1][2] - j) && (c[0][2] - i == c[2][2] - k)) {
							return cout << "Yes" << endl,0;
						}
					}
				}
			}
		}
	}
	return cout << "No" << endl, 0;
}
