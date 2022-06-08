#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

#define REP(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define ALL(a) (a).begin(), (a).end()

template <class T>
ostream &operator<<(ostream &o, const vector<T> &v)
{
    o << "{";
    for (int i = 0; i < (int)v.size(); i++) o << (i > 0 ? ", " : "") << v[i];
    o << "}";
    return o;
}


int main(void) {
	// cin, coutの結びつきを解除し、速くする
	cin.tie(0);
   	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<ll> vs;

	REP(i, N) {
		int a; cin >> a;
		vs.pb(a);
	}

	int count = 0;
	
	while(vs.size()) {
		ll max = *max_element(vs.begin(), vs.end());
		vs.erase(find(ALL(vs), max));

		ll c;
		REP(i, 29) {
			if (max <= pow(2, i)) {
				c  = pow(2, i) - max;
				break;
			}
		}

		if (binary_search(vs.begin(), vs.end(), c)) {
			vs.erase(find(ALL(vs), c));
			count += 1;
		}
	}
	cout << count << endl;
}
