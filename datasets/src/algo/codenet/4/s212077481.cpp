#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k, x;
	cin>>n>>k;
	set<int> st;
	for(int i = 0; i < k; i++){
		cin>>x;
		st.insert(x);
	}
	for(int i = n; ; i++){
		int v = i; bool flg = true;
		while(v){
			if(st.find(v%10) != st.end()){
				flg = false;
				break;
			}
			v /= 10;
		}
		if(flg){
			cout<<i<<endl;
			exit(0);
		}
	}

	return 0;
}