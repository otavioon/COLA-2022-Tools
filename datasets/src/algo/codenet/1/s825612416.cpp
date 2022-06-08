#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int c[3][3];
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cin >> c[i][j];
			if(i) c[i][j] -= c[0][j];
		}
	}
	if(c[1][0] == c[1][1] && c[1][1] == c[1][2] && c[2][0] == c[2][1] && c[2][1] == c[2][2]) Yes();
	else No();
	return 0;
}