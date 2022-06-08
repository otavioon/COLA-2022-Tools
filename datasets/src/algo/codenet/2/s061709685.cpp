#include <iostream>
#include <set>
using namespace std;
multiset <int> mp;
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		int x;
		cin >> x;
		mp.insert(x);
	}
	int ans = 0;
	while (! mp.empty()){
		multiset <int> :: iterator it = mp.end();
		-- it;
		int x = *it;
		mp.erase(it);
		for (int i = 30; i; -- i){
			int sum = 1 << i;
			if (mp.find(sum - x) != mp.end()){
				++ ans;
				mp.erase(sum - x);
			}
		}
	}
	cout << ans << endl;
}
