//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;
typedef vector<int> VI;


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)



int main() {

	int c[3][3];

	REP(i, 3) {
		REP(j, 3) {
			cin >> c[i][j];
		}
	}

	

	if (c[1][0] - c[0][0] == c[1][1] - c[0][1] && c[1][0] - c[0][0] == c[1][2] - c[0][2]) {
		if (c[2][0] - c[0][0] == c[2][1] - c[0][1] && c[2][0] - c[0][0] == c[2][2] - c[0][2]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

