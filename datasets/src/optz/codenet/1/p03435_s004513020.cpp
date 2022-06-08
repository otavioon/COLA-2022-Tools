// 基本テンプレート
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;
 
int board[5][5];
signed main() {
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cin >> board[i][j];
		}
	}

	const int UB = 100;
	for(int i=0; i<=UB; i++) {
		for(int j=0; j<=UB; j++) {
			for(int k=0; k<=UB; k++) {
				bool ok = true;
				for(int x=0; x<3; x++) {
					vector<int> vec(3);
					vec[0] = board[x][0] - i;
					vec[1] = board[x][1] - j;
					vec[2] = board[x][2] - k;
					ok &= (vec[0] == vec[1] and vec[1] == vec[2] and vec[2] == vec[0]);
				}

				if(ok) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
    return 0;
}