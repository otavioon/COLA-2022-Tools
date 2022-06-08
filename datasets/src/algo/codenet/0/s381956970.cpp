#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	string s;
	long long k;
	cin>>s;
	cin>>k;
	if (s.size() == 1) {
		cout<<(k/2)<<endl;
		return 0;
	}
	long long n = s.size();
	if (s[0] == s[n - 1]) {
		long long beg = 0;
		while (beg < n && s[beg] == s[0])
			beg++;
		long long end = n - 1;
		while (end > 0 && s[end] == s[n - 1])
			end--;
		if (beg == n - 1) {
			cout<<(n*k/2)<<endl;
			return 0;
		}
		long long res = 0;
		for (long long i = beg + 1; i <= end; i++)
			if (s[i] == s[i - 1]) {
				res++;
				s[i] = 'A';
			}
		res*=k;
		res += (beg / 2) + (n - 1 - end) / 2;
		res += (k - 1) * ((beg + n - 1 - end) / 2);
		cout<<res<<endl;
	} else {
		long long res = 0;
		for (long long i = 1; i < n; i++)
			if (s[i] == s[i - 1]) {
				res++;
				s[i] = 'A';
			}
		cout<<res*k<<endl;
	}
}