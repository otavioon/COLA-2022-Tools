#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long


int main(){
    int n, k;
    cin >> n >> k;
    set<int> se;

    rep(i,k){
        int x;
        cin >> x;
        se.insert(x);
    }
    bool f = 0;
    for (int i = n;; i++) {
		for (int s = i; s > 0; s /= 10) {
			if (se.count(s % 10)) {
				f = 1;
				break;
			}
		}
		if(!f) {
			cout << i << endl;
			return 0;
		}
		f = 0;
	}
}
