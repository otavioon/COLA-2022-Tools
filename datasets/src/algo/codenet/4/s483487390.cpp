#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

bool good(int x, set<int> &st) {
	while(x) {
		int d=x%10; x/=10;
		if(st.find(d)!=st.end())
			return false;
	}
	return true;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,k,d; cin>>n>>k;
	set<int> ok;
	for (int i=0; i<k; i++)
		cin>>d, ok.insert(d);	
	for (int i=0; i<100000; i++) {
		if(good(i,ok)&&i>=n) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
