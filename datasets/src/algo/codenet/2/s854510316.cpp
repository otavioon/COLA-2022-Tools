/* Accepted. */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
#define MAXN 200006
int n;
multiset<int> S;
int main() {
	cin >> n;
	for( int i = 0 , t ; i < n ; ++ i ) scanf("%d",&t) , S.insert(t);
	int ans = 0;
	while( !S.empty() ) {
		auto it = S.end(); --it;
		int x =  * ( it );
		S.erase( it );
		int k = log2( x ) + 1;
		if( S.count( (1<<k) - x ) ) S.erase(S.find((1<<k) - x) ) , ++ans;
	}
	cout << ans;
}
