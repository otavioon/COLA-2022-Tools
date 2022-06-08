#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int a; cin >> a;
			ans += a;
		}
	}
	cout << (ans % 3 ? "No\n" : "Yes\n");
	return 0;
}