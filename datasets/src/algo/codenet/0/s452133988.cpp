#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;

string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	ll n;	cin >> n;

	int i = 0, L = (int)s.size();
	ll fRes = 0;
	
	if(s[0] == s[L - 1]){
		while(i < L && (s[i] == s[0])){
			i++;
		}
		int j = L - 1;
		while(j >= 0 && (s[j] == s[L - 1])){
			j--;
		}

		if(j <= i){
			cout << ((L * n) / 2)<< '\n';
			return 0;
		}

		L = j + 1;
	}
	
	ll extra = 0;
	
	if(i > 0){
		ll a = i;
		ll b = (ll)s.size() - 1 - (L - 1);
		extra += (a / 2) + (b / 2) + ((a + b) / 2) * (n - 1);
	}

	while(i < L){
		int j = i;
		while(j < L && s[j] == s[i]){
			j++;
		}
		fRes += (ll)(j - 1 - i + 1) / 2;
		i = j;
	}

	//cerr << fRes << '\n';

	cout << fRes * n + extra << '\n';

	return 0;
}