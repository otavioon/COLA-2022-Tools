#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Nmax=200010;

int main() {
	int c[3][3];
	for(int i=0;i < 3;i++){
		for(int j=0;j < 3;j++){
			cin >> c[i][j];
		}
	}
	
	for(int i=0;i < 2;i++){
		set<int> set;
		for(int j=0;j < 3;j++){
			set.insert(c[j][i]-c[j][i+1]); //J=0 b1がすべて同じか調べる
		}					//b1,b2,b3が良ければa1,a2,a3も条件を満たす
		if(set.size() >= 2){ cout << "No" << endl; return 0;}
	}
	cout << "Yes" << endl;
	return 0;
}