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
		int x = *mp.rbegin();
		mp.erase(-- mp.end());
		for (int i = 30; i >= 0; -- i){
			int sum = 1 << i;
			if (mp.find(sum - x) != mp.end()){
				++ ans;
				mp.erase(mp.find(sum - x));
				break;
			}
		}
	}
	cout << ans << endl;
}
