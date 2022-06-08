#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {

	ll n, a, b;
	ll ans = 1;
	ll h[100000];

	cin >> n >> a >> b;

	rep(i, n) {
		cin >> h[i];
	}

	sort(h, h + n); 
	//h[0],h[1],.....h[n-2],h[n-1]

	ll l = 1;
	ll r = h[n - 1] / b + 1;
	

	while (r - l >= 1) {
		//cout << r - l << endl;
		ll t = (l + r) / 2; //t回で達成できるかどうか

		ll aa = a - b;
		ll sub = t;
		for (int j = n - 1; j >= 0; j--) {
			if (h[j] > b*t&&sub>0) {
				ll p;
				if ((h[j] - b * t) % aa == 0) p = (h[j] - b * t) / aa;
				else  p = (h[j] - b * t) / aa + 1;
				sub = sub - p;
				if (j==0&&sub >= 0) {
					ans = t;
					r = t;
					break;
				}
				else if (j == 0) {
					l = t + 1;
					break;
				}
			}else if (h[j] <= b * t&&sub >= 0) {
				ans = t;
				r = t;
				break;
			}
			else {
				l = t + 1;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}