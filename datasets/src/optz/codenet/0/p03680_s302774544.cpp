#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = INF;
	cin >> n;
	int ans = -1;
	int nums[n];
	for(int i = 0;i<n;++i)
	    cin >> nums[i];
	int curr = nums[0];
	for(int i = 1;i<n;++i) {
	   	if(nums[curr-1] == 2) {
			ans = i;
			break;
		}
		int temp = curr;
		curr = nums[temp-1];
	}	
		cout << ans+1 << '\n';
}
