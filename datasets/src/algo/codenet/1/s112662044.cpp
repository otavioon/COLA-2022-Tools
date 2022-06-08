#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int c[3][3];
	int sum = 0;
	rep(i,3)rep(j,3){
		cin >> c[i][j];
		sum += c[i][j];
	}
	if((c[0][0]+c[1][1]+c[2][2])*3 == sum )cout <<"Yes" << endl;
	else cout << "No" << endl;
}