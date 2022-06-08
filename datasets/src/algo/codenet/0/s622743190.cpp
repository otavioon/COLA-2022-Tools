#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <climits>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <tuple>

#define INF INT_MAX>>1 
#define SIZE 100010
#define MOD 1000000007
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep2(i, from, to) for(int i=(from); i<(int)(to); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define LLPair pair<ll, ll>
#define vint vector<int>
#define vll vector<ll>
typedef long long ll;

using namespace std;

int main(void){
	string str; cin >> str;
	string str2 = str+str;
	ll k; cin >> k;
	ll single = 0;
	ll joint = 0;
	ll count = 1;
	ll last = 0;
	ll top = 0;
	bool tflag = true;
	bool lflag = true;
	rep(i, str2.length()-2){
		if(str2[i] == str2[i+1]){
			count++;
			if(lflag && i==str.length()-2){
				last += count / 2;
				lflag = false;
			}
		} else{
			if(i < str.length()){
				if(tflag){
					top += count / 2;
					count = 1;
					tflag = false;
				} else{
					single += count / 2;
					count = 1;
				}
			} else{
				joint = count / 2;
				break;
			}
		}
	}
	joint = count / 2;

	ll ans = single * k;
	ans += joint * (k-1);
	if(k > 1) ans += last;
	ans += top;
	cout << ans << endl;
}

/*
int main(void){
	string str; cin >> str;
	string str2 = str+str;
	ll k; cin >> k;
	ll ans = 0;
	bool flag = false;
	if(str[0] == str[str.length()-1]) flag = true;

	ll count = 1;
	bool all = true;
	rep2(i, 0, str.length()-1){
		if(str[i] != str[i+1]){
			all = false;
			break;
		}
	}
	if(all){
		cout << (str.length()* k) /2;
		return 0;
	}

	if(!flag){
		rep2(i, 0, str.length()-1){
			if(str[i] == str[i+1]) count++;
			else{
				ans += count/2;
				count = 1;
			}
		}
		ans += count/2;
		ans *= k;
	} else{
		 if(str.length() == 1) {
			rep2(i, 0, str.length()-1){
				if(str[i] == str[i+1]) count++;
				else{
					ans += count /2;
					count = 1;
				}
			}
			ans += count/2;
			ans *= k;
			ans += k-1;
		}
		else if(str.length() == 1 || str[0] == str[1] || str[str.length()-2] == str[str.length()-1]){
			rep2(i, 0, str.length()-1){
				if(str[i] == str[i+1]) count++;
				else{
					ans += count /2;
					count = 1;
				}
			}
			ans += count/2;
			ans *= k;
		} else{
			rep2(i, 0, str.length()-1){
				if(str[i] == str[i+1]) count++;
				else{
					ans += count /2;
					count = 1;
				}
			}
			ans += count/2;
			ans *= k;
			ans += k-1;
		}
	}
	cout << ans << endl;

	return 0;
}
*/