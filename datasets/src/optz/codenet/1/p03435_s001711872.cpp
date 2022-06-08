#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<int(a);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;
using itn = int;
using namespace std;
int GCD(int a, int b){
    return b ? GCD(b, a%b) : a;
}
int main() {
	int c[3][3];
	rep(i,3){
		rep(j,3){
			cin >> c[i][j];
		}
	}
	int a[3]={};
	int b[3]={};
	a[0]=c[0][0];
	rep(i,3){
		b[i] = c[0][i]-a[0];
	}
	rep(i,2){
		a[i+1] = c[i+1][0]-b[0];
	}
	rep(i,3){
		rep(j,3){
			if(c[i][j]!=a[i]+b[j]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;	
}