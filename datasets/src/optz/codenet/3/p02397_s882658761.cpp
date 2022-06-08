#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define sum accumulate
typedef long long ll;
const int INF = 100000000;
const long INF64 = 1000000000000000ll;
const ll MOD = 998244353LL;
int main(){
	for(;;){
		vector<int>a(2);
		std::cin >> a[0]>>a[1];
		if(a[0]==0&&a[1]==0)exit(0);
		sort(all(a));
		std::cout << a[0]<<" "<<a[1] << std::endl;
	}
	
}
