#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,i,b[200],sum=0;
	cin >> n;
	for(i=1;i<n;i++){
		cin >> b[i];
	}
	for(i=1;i<=n;i++){
		if(i==1) sum+=b[1];
		else if(i==n) sum+=b[n-1];
		else sum+=min(b[i-1],b[i]);
	}
	cout << sum << endl;
	return 0;
}