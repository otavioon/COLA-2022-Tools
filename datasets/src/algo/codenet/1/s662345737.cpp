#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int c[3][3];
	REP(i,3) REP(j,3) cin >> c[i][j];
	
	REP(i,3){
		REP(j,3){
			if(c[i][j]+c[j][i]!=c[i][i]+c[j][j]){
				cout << "No\n";
				return 0;
			}
		}
	}
	
	cout << "Yes\n";
	
	return 0;
}