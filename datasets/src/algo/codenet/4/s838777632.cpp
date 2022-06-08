#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = 1000000007;

int main(void){
	int n, k; cin>>n>>k;
	int D[20] = {};
	for(int i=0;i<k;i++) cin>>D[i];

	for(int i=n;i<100000;i++) {
		int tmp = i;
		set<int> st;
		while(tmp!=0) {
			st.insert(tmp % 10);
			tmp /= 10;
		}
		bool flag = true;

		for(int j=0;j<k;j++) {
			if(st.count(D[j])) flag = false;
		}

		if(flag) {
			cout<< i <<endl;
			return 0;
		}
	}
	
	return 0;
}