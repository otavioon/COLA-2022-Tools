#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long int ll;

ll digit(ll num){
	if( num < 10)return 1;
	return 1 + digit(num/10);
}

ll myF(ll a,ll b){
	a = digit(a);
	b = digit(b);
	return max(a,b);
}

int main()
{
	ll n;
	cin>>n;
	ll sqrtN = sqrt((double)n) + 1;
	ll ans = 100000000;
	for(ll a = sqrtN; a > 0; a--){
		if( n % a == 0){
			ll b = n / a;
			//cout<<myF(a,b)<<endl;
			ans = min(ans,myF(a,b));
		}
	}
	cout<<ans<<endl;
	return 0;
}

