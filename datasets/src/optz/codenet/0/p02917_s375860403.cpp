#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,-1,0,1},dy={1,0,-1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<int> b(n-1),a(n);
	rep(i,n-1) cin >> b.at(i);
	a.at(n-1) = b.at(n-2);
	for(int i = n - 3; i >= 0; i--){
		a.at(i+1) = min(b.at(i), b.at(i+1));
	}
	a.at(0) = b.at(0);
	int ans = 0;
	rep(i,n) ans += a.at(i);
	cout << ans << endl;
}
