#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;
llint a[200005];
multiset<llint> S;

llint get(llint x)
{
	llint mul = 1;
	for(;x;x/=2) mul *= 2;
	return mul;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], S.insert(a[i]);
	
	llint ans = 0;
	while(S.size()){
		auto it = S.end(); it--;
		llint v = *it;
		S.erase(it);
		llint x = get(v);
		if(S.count(x-v)){
			ans++;
			S.erase(S.lower_bound(x-v));
		}
	}
	cout << ans << endl;
	
	return 0;
}