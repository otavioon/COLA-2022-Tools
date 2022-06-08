#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int> ans;
set<int> st;
multiset<int> ms;
int main(){
	int i,j,n;
	cin >> n;
	for(i=0;i<(1<<n);i++){
		int x; cin >> x;
		ms.insert(-x);
	}
	for(i=0;i<=n;i++){
		st.insert((1<<i) + 1);
	}
	auto it = ms.begin();
	ans.push_back(*it); i = 0;
	ms.erase(it);
	while(ans.size()<(1<<n)){
		auto it = ms.upper_bound(ans[i]);
		if(it==ms.end()){
			cout << "No" << endl;
			return 0;
		}
		int x = *it;
		ans.push_back(x); i++; ms.erase(it);
		if(st.count(i)){
			st.erase(i);
			i = 0;
		}
	}
	cout << "Yes" << endl;
}