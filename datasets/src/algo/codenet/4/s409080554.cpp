#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void test_case() {
	int n, k;
	cin >> n >> k;
	set<int> disliked;
	
	for(int i = 0; i < k; i ++) {
		int temp;
		cin >> temp;
		disliked.insert(temp);
	}
	debug() << imie(disliked);
	bool bigger = false;
	int arr[4]={0};
	int cnt = 3;
	while(n) {
		int m = n % 10;
		int found = m;
		if (disliked.find(m) != disliked.end()) {
			found = -1;
			for(int i = m + 1; i <= 9; i ++) {
				if(disliked.find(i) == disliked.end()) {
					bigger = false;
					found = i;
					break;
				}
			}
			if(found == -1) {
				bigger = true;
				for(int i = 0; i < m; i ++) {
					if(disliked.find(i) == disliked.end()) {
						found = i;
						break;
					}
				}	
			}
		}
		debug() << imie(found);
		arr[cnt --] = found;
		n /= 10;
	}
	for(int i = 0; i < 4; i ++) {
		cout << arr[i];
	}
	cout << "\n";
	//assert(!bigger);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1; 
	//scanf("%d", &t);
	while(t --) {
		test_case();
	}
	return 0;
}
