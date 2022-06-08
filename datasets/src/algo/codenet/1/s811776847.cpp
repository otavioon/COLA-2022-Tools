#include<bits/stdc++.h>

using namespace std;

int main(){
	int sum = 0;
	for(int i = 0; i < 9; ++i){
		int x; cin >> x;
		sum += x;
	}
	cout << (sum%3==0 ? "Yes" : "No") << endl;
}