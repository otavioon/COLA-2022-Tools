#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<tuple>
#include<functional>
#include<iterator>
#include<cmath>
#include<cctype>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = INF+7;

struct edge{int to,cost;};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int a[n],b[n],c[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	for(int i=0;i<n;i++) cin >> c[i];

	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);

	int la[n],lec[n];
	int ida=0,idc=0;
	for(int i=0;i<n;i++){
		while(ida < n && a[ida] < b[i]) ida++;
		la[i]=ida;
		while(idc < n && c[idc] <= b[i]) idc++;
		lec[i]=idc;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ans += 1LL*la[i]*(n-lec[i]);
	}
	cout << ans << "\n";
	
	return 0;
}