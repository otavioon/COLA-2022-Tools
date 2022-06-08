#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define inf 1e+9
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b){ a>b?:a=b; }
template<class T, class C> void chmin(T& a, C b){ a<b?:a=b; }

int main (){
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n,k,ans=0;
	string s;
	cin >> n;
	ll a[n],b[n];
	rep(i,n-1){
		cin >> b[i];
	}
	ans += b[0];
	ans += b[n-2];

	for(int i=1;i<n-1;i++){
		ans += min({b[i-1],b[i]});
	}	

	cout << ans << endl;
}