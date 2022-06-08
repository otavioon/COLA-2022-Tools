#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <functional>

using namespace std;
using ll = long long;

#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define PAIR pair<int,int>
#define MP make_pair
#define VP vector<pair<int,int>>
#define VS vector<string>
#define QUE queue<int>
#define DEQ deque<int>
#define PQUE priority_queue<int> //5,5,4,3,3,2,...
#define REPQUE priority_queue<int, vector<int>, greater<int>> //1,1,2,3,4,4,5,...
#define SUM(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll MOD = (ll)1e9 + 7;
const ll INF = 1e12;

int main() {
	int C[3][3];
	REP(i, 3)REP(j, 3)cin >> C[i][j];
	if (C[0][0] + C[1][1] + C[2][2] == C[0][1] + C[1][2] + C[2][0] && C[0][1] + C[1][2] + C[2][0] == C[0][2] + C[1][0] + C[2][1]) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
