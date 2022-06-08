#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;
int n;
int main(void){
	cin >> n;
	int b[n-1];
	for(int i=0;i<n-1;i++){
		cin >> b[i]; 
	}
	int a[n];
	int ans =0;
	for(int i=0;i<n;i++){
		if(i==0){
			a[i] = b[i];
			ans += a[i];
			continue;
		}
		if(i==n-1){
			a[i] = b[i-1];
			ans += a[i];
			continue;
		}
		a[i] = min(b[i-1],b[i]);
		ans += a[i];
	}
	rep(i,n)cout << a[i] << endl;
	cout << ans;
return 0;
}

