#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;
multiset<llint> S, rem;

int main(void)
{
	cin >> n;
	llint a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		rem.insert(a);
	}
	for(int i = 1; i < 33; i++) S.insert(1LL<<i);
	
	llint ans = 0;
	while(rem.size() >= 2){
		auto p = rem.end();
		p--;
		llint x = *p;
		rem.erase(p);
		
		llint y = *(S.upper_bound(x))-x;
		auto q = rem.lower_bound(y);
		if(q != rem.end() && *q == y){
			ans++;
			rem.erase(q);
		}
	}
	cout << ans << endl;
	
	return 0;
}