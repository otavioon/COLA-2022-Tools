#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int arr[N], L[N], R[N];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	int n;
	cin >> n;
	multiset<int> st;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		st.insert(num);
	}
	int ans = 0;
	while(!st.empty()){
		int x = *st.rbegin();
		st.erase(st.find(x));
		int num = 1;
		while(num <= x){
			num *= 2;
		}
		if(st.find(num - x) == st.end()){
			continue;
		}
		st.erase(st.find(num - x));
		ans++;
	}
	cout << ans;
}