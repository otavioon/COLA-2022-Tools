#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
	int n;
	int a;
	int idx = 1;
	unordered_set<int> s;
	cin >> n;
	vector<int> v(n + 1);
	for(int i=1; i<=n; i++){
		cin >> a;
		v[i] = a;
	}
	while(1){
		if(s.count(v[idx])){
			cout << -1;
			return 0;
		} else {
			s.insert(v[idx]);
			if(v[idx] == 2) {
				cout << s.size();
				return 0;
			}
			idx = v[idx];
		}
	}
	return 0;
}

