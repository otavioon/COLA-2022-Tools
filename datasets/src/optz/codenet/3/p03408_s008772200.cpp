#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#define INF 1000000007
using namespace std;

int main(void) {
	int n,m,count,ans=0;
	cin >> n;
	vector<string> s(n);
	for(int i=0; i<n; i++)cin >> s[i];
	cin >> m;
	vector<string> t(m);
	for(int i=0; i<m; i++)cin >> t[i];
	for(int i=0; i<n; i++){
		count=0;
		for(int j=0; j<n; j++)if(s[i]==s[j])count++;
		for(int j=0; j<m; j++)if(s[i]==t[j])count--;
		ans=max(ans,count);
	}
	cout << ans << endl;
	return 0;
}
