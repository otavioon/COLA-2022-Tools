#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll b1,b2,b3;
	cin>>b1>>b2>>b3;
	bool ans=true;
	for(int i=0;i<2;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		ll now=x-b1;
		if(now!=y-b2||now!=z-b3){
			ans=false;
		}
	}
	cout << (ans?"Yes":"No");
	return 0;
}