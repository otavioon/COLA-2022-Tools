#include <iostream>
#include<algorithm>
#include<stack>
#include<set>
#include <cmath>
using namespace std;
const long long N = 105;
long long M = 1000000007;
set<int>d;
bool q(int n) {
	while (n) {
		if (d.find(n % 10) != d.end()) {
			return 0;
		}
		n /= 10;
	}
	return 1;
}
int main() {
	int n,k;
	cin>>n >> k;
	
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		d.insert(a);
	}
	for (int i = n;; i++) {
		if (q(i)) {
			cout << i;
			return 0;
		}
		else continue;
	}

}