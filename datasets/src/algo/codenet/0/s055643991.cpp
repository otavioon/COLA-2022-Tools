#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	string s;cin >> s;
	int n = s.length();
	long k;cin >> k;
	long ans = 0;
	if(s.length() == 1){
		cout << k/2 << endl;return 0;
	}
	
	
		int l = 0,r = n-1;
		while(s[l] == s[0])l++;
		while(s[r] == s[0])r--;
	//	cout <<l << " "<< r << endl;
		int a = l,b = n-r-1;
		if(l > r){
			cout << (k*a)/2 << endl;
			return 0;
		}
		int count = 1;
		for(int i = l+1;i<=r;i++){
			if(s[i] == s[i-1])count++;
			else{
				ans += k*(count/2);
				count = 1;
			}
		}
		ans+= k*(count/2);
		//cout << ans << endl;
		if(s[0] == s[n-1]){
			ans +=  (k-1)*(a+b)/2 + (a/2) + (b/2);
		}
		else{
			ans += (k)*(a/2 + b/2);
		}
		//cout << a <<" " << b << endl;
		cout << ans << endl;
	
	
	
	return 0;
}