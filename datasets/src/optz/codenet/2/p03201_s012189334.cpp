#include <bits/stdc++.h>
using namespace std;

map <int, int> mp;

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		mp[x]++;
	}
	int res = 0;
	while (!mp.empty()){
		map <int, int> :: iterator it = mp.end();
		it--;
		int x = it->first;
		mp[x]--;
		if (mp[x] == 0) mp.erase(x);
		int tot;
		for (tot = 1; tot <= x; tot <<= 1);
		if (mp.count(tot - x)){
			mp[tot - x]--, res++;
			if (mp[tot - x] == 0) mp.erase(tot - x);
		}
	}
	printf("%d\n", res);
	return 0;
}
