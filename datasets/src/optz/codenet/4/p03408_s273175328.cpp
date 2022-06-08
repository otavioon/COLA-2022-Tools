#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int N, M, mcnt=0;
	cin >> N;
	multiset<string> s1, t;
	set<string> s2;
	for(int i=0; i<N; i++){
		string r;
		cin >> r;
		s1.insert(r);
		s2.insert(r);
	}
	cin >> M;
	for(int i=0; i<M; i++){
		string r;
		cin >> r;
		t.insert(r);
	}
	for(auto i:s2){
		int cnt = 0;
		cnt += s1.count(i);
		cnt -= t.count(i);
		mcnt = max(cnt, mcnt);
	}
	cout << mcnt << endl;
	
	
	return 0;
}