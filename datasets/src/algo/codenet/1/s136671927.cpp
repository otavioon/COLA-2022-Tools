#include<iostream>
#include<math.h>
#include<algorithm>
#define ll long long int
#define FOR(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n)
  
using namespace std;

int main() {
	int c [ 3 ] [ 3 ];
	int x, y, z;
	REP(i,3) {
		REP(j,3) {
			cin >> c [ i ] [ j ];
		}
	}
	REP1(k,3) {
		x = c [ 0 ] [ 0 ] - c [ k ] [ 0 ];
		y = c [ 0 ] [ 1 ] - c [ k ] [ 1 ];
		z = c [ 0 ] [ 2 ] - c [ k ] [ 2 ];
		if ( x != y || y != z ) {
			cout << "No" << endl;
			return 0;
		} 
	} 
	cout << "Yes" << endl;
	return 0;	
}