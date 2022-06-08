#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c;
long long h[100010];

bool is(long long t){
	long long ans = 0;
	for(int i = 0;i < n;i++){
		int tt = h[i] - b * t;
		if(tt > 0){
			ans += (tt+c-1)/c;
		}
	}
	return t >= ans;
}

int main(){
	cin >> n >> a >> b;

	for(int i = 0;i < n;i++){
		cin >> h[i];
	}

	c = a-b;

	long long left = 0, right = 1000000007;

	while(right-left > 1){
		long long mid = left + (right-left)/2;
		if(is(mid)) right = mid;
		else left = mid;
	}

	cout << right << endl;
	return 0;
}




