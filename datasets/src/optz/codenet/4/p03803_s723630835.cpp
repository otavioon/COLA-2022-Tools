#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second

int main(){
	int a,b;
	cin >> a >> b;

	a += 13 - 2;
	b += 13 - 2;
	a %= 13;
	b %= 13;

	if(a < b) {
		cout << "Bob" << endl;
	}else if(a > b) {
		cout << "Alice" << endl;
	}else {
		cout << "Draw" << endl;
	}
	return 0;
}
